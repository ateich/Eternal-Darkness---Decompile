typedef int BOOL;
typedef int s32;
typedef unsigned int u32;

typedef struct EXIControl {
    void *exiCallback;
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
extern BOOL OSDisableInterrupts(void);
extern void OSRestoreInterrupts(BOOL enabled);
extern void __OSUnmaskInterrupts(u32 interrupts);
extern BOOL __EXIProbe_80206F50(s32 chan);

BOOL EXIDeselect(s32 chan)
{
    EXIControl *exi = &Ecb_80640AA8[chan];
    u32 cpr;
    u32 reg;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if (!(exi->state & 4)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state &= ~4;
    reg = 0xCC006800;
    reg += chan * 0x14;
    cpr = *(volatile u32 *)reg;
    *(volatile u32 *)reg = cpr & 0x405;

    if (exi->state & 8) {
        switch (chan) {
        case 0:
            __OSUnmaskInterrupts(0x100000);
            break;
        case 1:
            __OSUnmaskInterrupts(0x20000);
            break;
        }
    }

    OSRestoreInterrupts(enabled);
    if (chan != 2 && (cpr & 0x80)) {
        return __EXIProbe_80206F50(chan) ? 1 : 0;
    }
    return 1;
}
