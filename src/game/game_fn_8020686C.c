typedef int BOOL;
typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct EXIControl {
    void *exiCallback;
    void *tcCallback;
    char pad_08[4];
    volatile u32 state;
    s32 immLen;
    void *immBuf;
    char pad_18[0x28];
} EXIControl;

extern EXIControl Ecb_80640AA8[3];

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern void __OSUnmaskInterrupts(u32);
extern void fn_80206E8C(s32, s32, s32, s32);

volatile u32 __EXIRegs[15] : 0xCC006800;

BOOL EXIImm(s32 chan, void *buf, s32 len, u32 type, void *callback)
{
    EXIControl *exi = &Ecb_80640AA8[chan];
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if ((exi->state & 3) || !(exi->state & 4)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->tcCallback = callback;
    if (exi->tcCallback) {
        fn_80206E8C(chan, 0, 1, 0);
        __OSUnmaskInterrupts(0x200000u >> (3 * chan));
    }

    exi->state |= 2;

    if (type != 0) {
        u32 data;
        long i;

        i = 0;
        data = 0;
        while (i < len) {
            data |= ((u8 *)buf)[i] << ((3 - i) * 8);
            i++;
        }
        __EXIRegs[chan * 5 + 4] = data;
    }

    exi->immBuf = buf;
    exi->immLen = (type != 1) ? len : 0;

    __EXIRegs[chan * 5 + 3] = (type << 2) | 1 | ((len - 1) << 4);

    OSRestoreInterrupts(enabled);
    return 1;
}
