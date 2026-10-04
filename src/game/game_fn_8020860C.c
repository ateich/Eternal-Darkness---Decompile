typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef int BOOL;

typedef struct OSContext OSContext;
typedef s16 __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt interrupt, OSContext *context);
typedef void (*SICallback)(s32 chan, u32 error, OSContext *context);
typedef void (*SITypeAndStatusCallback)(s32 chan, u32 type);

typedef struct OSAlarm {
    void *handler;
    u32 tag;
    s64 fire;
    struct OSAlarm *prev;
    struct OSAlarm *next;
    s64 period;
    s64 start;
} OSAlarm;

typedef struct SIPacket {
    s32 chan;
    void *output;
    u32 outputBytes;
    void *input;
    u32 inputBytes;
    SICallback callback;
    s64 fire;
} SIPacket;

typedef struct SIControl {
    s32 chan;
    u32 poll;
    u32 inputBytes;
    void *input;
    SICallback callback;
} SIControl;

static SIControl Si = {
    -1, 0, 0, 0, 0,
};
static SIPacket Packet[4];
static OSAlarm Alarm[4];
static u32 Type[4] = {
    8, 8, 8, 8,
};
static s64 TypeTime[4];
static s64 XferTime[4];
static SITypeAndStatusCallback TypeCallback[4][4];
static __OSInterruptHandler RDSTHandler[4];
static BOOL InputBufferValid[4];
static u32 InputBuffer[4][2];
static volatile u32 InputBufferVcount[4];

extern u32 lbl_8064D8D0;

extern volatile u32 __SIRegs[64] : 0xCC006400;
extern u32 __OSBusClock : 0x800000F8;

extern u32 fn_80208310(void);
extern s64 __OSGetSystemTime(void);
extern BOOL fn_80208C4C(s32 chan, void *output, u32 outputBytes, void *input,
                        u32 inputBytes, SICallback callback);
extern BOOL fn_8020A93C(OSAlarm *alarm);
extern BOOL fn_8020906C(s32 chan);
extern u32 fn_802181F4(void);
extern BOOL SITransfer(s32 chan, void *output, u32 outputBytes, void *input,
                       u32 inputBytes, SICallback callback, s64 delay);
extern void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context);

static inline BOOL SIIsChanBusy(s32 chan)
{
    return (Packet[chan].chan != -1 || Si.chan == chan);
}

static inline void SITransferNext(s32 chan)
{
    int i;
    SIPacket *packet;

    for (i = 0; i < 4; ++i) {
        ++chan;
        chan %= 4;
        packet = &Packet[chan];
        if (packet->chan != -1 && packet->fire <= __OSGetSystemTime()) {
            if (fn_80208C4C(packet->chan, packet->output, packet->outputBytes,
                            packet->input, packet->inputBytes, packet->callback)) {
                fn_8020A93C(&Alarm[chan]);
                packet->chan = -1;
            }
            break;
        }
    }
}

void SIInterruptHandler_8020860C(__OSInterrupt interrupt, OSContext *context)
{
    u32 reg;

    reg = __SIRegs[13];

    if ((reg & 0xc0000000) == 0xc0000000) {
        s32 chan;
        u32 sr;
        SICallback callback;

        chan = Si.chan;
        sr = fn_80208310();
        callback = Si.callback;
        Si.callback = 0;

        SITransferNext(chan);

        if (callback) {
            callback(chan, sr, context);
        }

        sr = __SIRegs[14];
        sr &= 0xf000000 >> (8 * chan);
        __SIRegs[14] = sr;

        if (Type[chan] == 0x80 && !SIIsChanBusy(chan)) {
            SITransfer(chan, &lbl_8064D8D0, 1, &Type[chan], 3, GetTypeCallback_802093FC,
                       ((65 * (__OSBusClock / 4 / 125000)) / 8));
        }
    }

    if ((reg & 0x18000000) == 0x18000000) {
        int i;
        u32 vcount;
        u32 x;

        vcount = fn_802181F4() + 1;
        x = (Si.poll & 0x03ff0000) >> 16;

        for (i = 0; i < 4; ++i) {
            if (fn_8020906C(i)) {
                InputBufferVcount[i] = vcount;
            }
        }

        for (i = 0; i < 4; ++i) {
            if (!(Si.poll & (0x80000000 >> (31 - 7 + i)))) {
                continue;
            }
            if (InputBufferVcount[i] == 0 || InputBufferVcount[i] + (x / 2) < vcount) {
                return;
            }
        }

        for (i = 0; i < 4; ++i) {
            InputBufferVcount[i] = 0;
        }

        for (i = 0; i < 4; ++i) {
            if (RDSTHandler[i]) {
                RDSTHandler[i](interrupt, context);
            }
        }
    }
}
