typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct OSContext OSContext;

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

extern EXIControl Ecb_80640AA8[3];
extern void EXIIntrruptHandler_802075FC(s16 interrupt, OSContext *context);
extern void TCIntrruptHandler_802076C4(s16 interrupt, OSContext *context);
extern void EXTIntrruptHandler_802078DC(s16 interrupt, OSContext *context);
extern void __OSMaskInterrupts(u32 interrupts);
extern void __OSSetInterruptHandler(s16 interrupt, void (*handler)(s16, OSContext *));
extern u32 OSGetConsoleType(void);
extern s32 __EXIProbe_80206F50(s32 chan);

volatile u32 __EXIRegs[15] : 0xCC006800;

void EXIInit(void)
{
    __OSMaskInterrupts(0x7F8000);

    __EXIRegs[0] = 0;
    __EXIRegs[5] = 0;
    __EXIRegs[10] = 0;
    __EXIRegs[0] = 0x2000;

    __OSSetInterruptHandler(9, EXIIntrruptHandler_802075FC);
    __OSSetInterruptHandler(10, TCIntrruptHandler_802076C4);
    __OSSetInterruptHandler(11, EXTIntrruptHandler_802078DC);
    __OSSetInterruptHandler(12, EXIIntrruptHandler_802075FC);
    __OSSetInterruptHandler(13, TCIntrruptHandler_802076C4);
    __OSSetInterruptHandler(14, EXTIntrruptHandler_802078DC);
    __OSSetInterruptHandler(15, EXIIntrruptHandler_802075FC);
    __OSSetInterruptHandler(16, TCIntrruptHandler_802076C4);

    if (OSGetConsoleType() & 0x10000000) {
        *(volatile u32 *)0x800030C4 = 0;
        *(volatile u32 *)0x800030C0 = 0;
        Ecb_80640AA8[1].idTime = 0;
        Ecb_80640AA8[0].idTime = 0;
        __EXIProbe_80206F50(0);
        __EXIProbe_80206F50(1);
    }
}
