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
    void *tcCallback;
    void *extCallback;
    volatile u32 state;
    void *immBuf;
    u32 immLen;
    u32 dev;
    u32 id;
    s32 idTime;
    char pad_24[0x1C];
} EXIControl;

extern EXIControl Ecb_80640AA8[3];
extern void OSClearContext(OSContext *context);
extern void OSSetCurrentContext(OSContext *context);

static void EXIIntrruptHandler_802075FC(s16 interrupt, OSContext *context)
{
    OSContext exceptionContext;
    s32 chan = (interrupt - 9) / 3;
    u32 reg = 0xCC006800;
    EXICallback callback;

    reg += chan * sizeof(EXIRegisters);
    *(volatile u32 *)reg = (*(volatile u32 *)reg & 0x7F5) | 2;
    callback = Ecb_80640AA8[chan].exiCallback;
    if (callback != 0) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
