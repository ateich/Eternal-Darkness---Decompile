typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct OSContext {
    double align;
    char data[0x2C8];
} OSContext;

typedef struct EXIRegisters {
    u32 csr;
    u32 mar;
    u32 length;
    u32 control;
    u32 immediateData;
} EXIRegisters;

typedef void (*EXICallback)(s32 chan, OSContext *context);

typedef struct EXIControl {
    EXICallback exiCallback;
    EXICallback tcCallback;
    EXICallback extCallback;
    volatile u32 state;
    void *immBuf;
    s32 immLen;
    u32 dev;
    u32 id;
    s32 idTime;
    char pad_24[0x1C];
} EXIControl;

extern EXIControl Ecb_80640AA8[3];
extern void __OSMaskInterrupts(u32 interrupts);
extern void OSClearContext(OSContext *context);
extern void OSSetCurrentContext(OSContext *context);

static void TCIntrruptHandler_802076C4(s16 interrupt, OSContext *context)
{
    OSContext exceptionContext;
    s32 chan = (interrupt - 10) / 3;
    EXIControl *exi = &Ecb_80640AA8[chan];
    volatile u8 *regs = (u8 *)0xCC006800;
    s32 offset;
    EXICallback callback;

    __OSMaskInterrupts(0x80000000 >> interrupt);
    offset = chan * sizeof(EXIRegisters);
    *(volatile u32 *)(regs + offset) =
        (*(volatile u32 *)(regs + offset) & 0x7F5) | 8;
    callback = exi->tcCallback;
    if (callback != 0) {
        exi->tcCallback = 0;
        if (exi->state & 3) {
            if ((exi->state & 2) && exi->immBuf != 0) {
                s32 i;
                u8 *buf = exi->immBuf;
                s32 len = exi->immLen;
                u32 data = *(volatile u32 *)(regs + offset + 0x10);

                for (i = 0; i < len; i++) {
                    *buf++ = data >> ((3 - i) * 8);
                }
            }
            exi->state &= ~3;
        }
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
