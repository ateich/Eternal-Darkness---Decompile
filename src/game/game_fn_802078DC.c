typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct OSContext {
    char data[0x2C8];
} OSContext;

typedef struct EXIControl {
    void *exiCallback;
    void *tcCallback;
    void (*extCallback)(s32 chan, OSContext *context);
    volatile u32 state;
    void *immBuf;
    s32 immLen;
    u32 dev;
    u32 id;
    s32 idTime;
    char pad_24[0x1C];
} EXIControl;

typedef void (*EXICallback)(s32 chan, OSContext *context);

extern EXIControl Ecb_80640AA8[3];
extern void __OSMaskInterrupts(u32 interrupts);
extern void OSClearContext(OSContext *context);
extern void OSSetCurrentContext(OSContext *context);
volatile u32 __EXIRegs[15] : 0xCC006800;

void EXTIntrruptHandler_802078DC(s16 interrupt, OSContext *context)
{
    OSContext exceptionContext;
    s32 chan = (interrupt - 11) / 3;
    EXIControl *exi;
    EXICallback callback;

    __OSMaskInterrupts(0x700000U >> (u32)(chan * 3));
    __EXIRegs[chan * 5] = 0;
    exi = &Ecb_80640AA8[chan];
    callback = exi->extCallback;
    exi->state &= ~8;
    if (callback != 0) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        exi->extCallback = 0;
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
