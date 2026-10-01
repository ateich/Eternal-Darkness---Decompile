typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct OSContext {
    double align;
    char data[0x2C0];
} OSContext;

typedef void (*EXICallback)(s32 chan, OSContext *context);

typedef struct EXIControl {
    EXICallback exiCallback;
    EXICallback tcCallback;
    EXICallback extCallback;
    volatile u32 state;
    s32 immLen;
    void *immBuf;
    u32 dev;
    u32 id;
    s32 idTime;
    char pad_24[0x1C];
} EXIControl;

extern EXIControl Ecb_80640AA8[3];
extern void __OSMaskInterrupts(u32 interrupts);
extern void OSClearContext(OSContext *context);
extern void OSSetCurrentContext(OSContext *context);
volatile u32 __EXIRegs[15] : 0xCC006800;

static inline u32 EXIClearInterrupts(s32 chan, s32 exi, s32 tc, s32 ext)
{
    u32 cpr;
    u32 prev;

    prev = cpr = __EXIRegs[chan * 5];
    cpr &= 0x7F5;
    if (exi) {
        cpr |= 2;
    }
    if (tc) {
        cpr |= 8;
    }
    if (ext) {
        cpr |= 0x800;
    }
    __EXIRegs[chan * 5] = cpr;
    return prev;
}

static inline void CompleteTransfer(s32 chan)
{
    EXIControl *exi = &Ecb_80640AA8[chan];
    u8 *buf;
    u32 data;
    s32 i;
    s32 len;

    if (exi->state & 3) {
        if ((exi->state & 2) && (len = exi->immLen)) {
            buf = exi->immBuf;
            data = __EXIRegs[chan * 5 + 4];
            for (i = 0; i < len; i++) {
                *buf++ = (u8)((data >> ((3 - i) * 8)) & 0xff);
            }
        }
        exi->state &= ~3;
    }
}

void TCIntrruptHandler_802076C4(s16 interrupt, OSContext *context)
{
    OSContext exceptionContext;
    s32 chan;
    EXIControl *exi;
    EXICallback callback;

    chan = (interrupt - 10) / 3;
    exi = &Ecb_80640AA8[chan];
    __OSMaskInterrupts(0x80000000 >> interrupt);
    EXIClearInterrupts(chan, 0, 1, 0);
    callback = exi->tcCallback;
    if (callback) {
        exi->tcCallback = 0;
        CompleteTransfer(chan);

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);

        callback(chan, context);

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
