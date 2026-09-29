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
extern BOOL __EXIProbe_80206F50(s32 chan);
extern void __OSMaskInterrupts(u32 interrupts);

BOOL EXISelect(s32 chan, u32 dev, u32 freq)
{
    EXIControl *exi = &Ecb_80640AA8[chan];
    u32 reg;
    u32 cpr;
    BOOL enabled = OSDisableInterrupts();

    if ((exi->state & 4) ||
        (chan != 2 &&
         ((dev == 0 && !(exi->state & 8) && !__EXIProbe_80206F50(chan)) ||
          !(exi->state & 0x10) || exi->dev != dev))) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state |= 4;
    reg = 0xCC006800;
    reg += chan * 0x14;
    cpr = *(volatile u32 *)reg;
    cpr &= 0x405;
    cpr |= ((1 << dev) << 7) | (freq << 4);
    *(volatile u32 *)reg = cpr;

    if (exi->state & 8) {
        switch (chan) {
        case 0:
            __OSMaskInterrupts(0x100000);
            break;
        case 1:
            __OSMaskInterrupts(0x20000);
            break;
        }
    }

    OSRestoreInterrupts(enabled);
    return 1;
}
