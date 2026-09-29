typedef int BOOL;
typedef int s32;
typedef long long s64;
typedef unsigned int u32;

typedef struct EXIControl {
    void *exiCallback;
    void *tcCallback;
    char pad_08[4];
    volatile u32 state;
    s32 immLen;
    void *immBuf;
    char pad_18[8];
    u32 idTime;
    char pad_24[0x1C];
} EXIControl;

extern EXIControl Ecb_80640AA8[3];
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern s64 OSGetTime(void);
extern s64 fn_800F5ECC(s64, s64);

volatile u32 __EXIRegs[15] : 0xCC006800;
volatile s32 __OSDeviceCode[3] : 0x800030C0;

BOOL __EXIProbe_80206F50(s32 chan)
{
    EXIControl *exi = &Ecb_80640AA8[chan];
    if (chan == 2) {
        return 1;
    }

    {
    BOOL enabled;
    BOOL rc = 1;
    u32 val;
    u32 cpr;

    enabled = OSDisableInterrupts();
    cpr = __EXIRegs[chan * 5];
    if (!(exi->state & 8)) {
        if (cpr & 0x800) {
            val = __EXIRegs[chan * 5];
            val &= 0x7F5;
            val |= 0x800;
            __EXIRegs[chan * 5] = val;
            exi->idTime = 0;
            __OSDeviceCode[chan] = 0;
        }
        if (cpr & 0x1000) {
            s32 time;
            u32 ticksPerMillisecond = (*(u32 *)0x800000F8 / 4) / 1000;
            time = (s32)fn_800F5ECC(
                fn_800F5ECC(OSGetTime(), ticksPerMillisecond), 100) + 1;
            if (__OSDeviceCode[chan] == 0) {
                __OSDeviceCode[chan] = time;
            }
            if (time - __OSDeviceCode[chan] < 3) {
                rc = 0;
            }
        } else {
            exi->idTime = 0;
            __OSDeviceCode[chan] = 0;
            rc = 0;
        }
    } else if (!(cpr & 0x1000) || (cpr & 0x800)) {
        exi->idTime = 0;
        __OSDeviceCode[chan] = 0;
        rc = 0;
    }

    OSRestoreInterrupts(enabled);
    return rc;
    }
}
