typedef int BOOL;
typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 OSGetConsoleType(void);
extern BOOL EXISelect(s32 chan, u32 dev, u32 freq);
extern BOOL EXIDeselect(s32 chan);
extern BOOL EXIImm(s32 chan, void* buf, s32 len, u32 type, void* callback);
extern BOOL EXISync(s32 chan);
extern BOOL EXILock(s32 chan, u32 dev, void* callback);
extern BOOL EXIUnlock(s32 chan);

static s32 Chan;
static u32 Dev;
static u32 Enabled;
static u32 BarnacleEnabled;

u32 InitializeUART(u32 baudRate)
{
    if (BarnacleEnabled == 0xa5ff005a) {
        return 0;
    }

    if (!(OSGetConsoleType() & 0x10000000)) {
        Enabled = 0;
        return 2;
    } else {
        Chan = 0;
        Dev = 1;
        Enabled = 0xa5ff005a;
        return 0;
    }
}

static int QueueLength(void)
{
    u32 cmd;

    if (!EXISelect(Chan, Dev, 3))
        return -1;

    cmd = 0x800400u << 6;
    EXIImm(Chan, &cmd, 4, 1, 0);
    EXISync(Chan);
    EXIImm(Chan, &cmd, 1, 0, 0);
    EXISync(Chan);
    EXIDeselect(Chan);

    return 16 - (int)((cmd >> 24) & 0xff);
}

u32 WriteUARTN(void* buf, u32 len)
{
    u32 cmd;
    int qLen;
    long xLen;
    char* ptr;
    BOOL locked;
    u32 error;

    if (Enabled != 0xa5ff005a)
        return 2;

    locked = EXILock(Chan, Dev, 0);
    if (!locked) {
        return 0;
    }

    for (ptr = (char*)buf; ptr - (char*)buf < len; ptr++) {
        if (*ptr == '\n')
            *ptr = '\r';
    }

    error = 0;
    cmd = (0x800400u | 0x2000000) << 6;
    while (len) {
        qLen = QueueLength();
        if (qLen < 0) {
            error = 3;
            break;
        }

        if (qLen < 12 && qLen < len)
            continue;

        if (!EXISelect(Chan, Dev, 3)) {
            error = 3;
            break;
        }

        EXIImm(Chan, &cmd, 4, 1, 0);
        EXISync(Chan);

        while (qLen && len) {
            if (qLen < 4 && qLen < len)
                break;
            xLen = (len < 4) ? (long)len : 4;
            EXIImm(Chan, (void*)buf, xLen, 1, 0);
            (u8*)buf += xLen;
            len -= xLen;
            qLen -= xLen;
            EXISync(Chan);
        }
        EXIDeselect(Chan);
    }

    EXIUnlock(Chan);
    return error;
}
