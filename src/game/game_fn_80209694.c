typedef signed int s32;
typedef signed long long s64;
typedef unsigned int u32;

typedef struct OSContext OSContext;
typedef void (*SICallback)(s32 chan, u32 error, OSContext *context);

typedef struct SIControl {
    s32 chan;
    u32 poll;
    u32 inputBytes;
    void *input;
    SICallback callback;
} SIControl;

extern SIControl Si_802FCA20;
extern u32 Type_802FCA34[4];
extern s64 TypeTime_80640C88[4];
u32 cmdTypeAndStatus;
u32 lbl_8064D8D0;
extern u32 __OSBusClock : 0x800000F8;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 enabled);
extern s64 __OSGetSystemTime(void);
extern s32 SITransfer(s32 chan, void *output, u32 outputBytes, void *input,
                      u32 inputBytes, SICallback callback, s64 delay);
extern void GetTypeCallback_802093FC(s32 chan, u32 error,
                                     OSContext *context);

u32 SIGetType(s32 chan)
{
    u32 enabled;
    u32 type;
    s64 diff;

    enabled = OSDisableInterrupts();
    type = Type_802FCA34[chan];
    diff = __OSGetSystemTime() - TypeTime_80640C88[chan];

    if (Si_802FCA20.poll & (0x80 >> chan)) {
        if (type != 8) {
            TypeTime_80640C88[chan] = __OSGetSystemTime();
            OSRestoreInterrupts(enabled);
            return type;
        }
        Type_802FCA34[chan] = 0x80;
        type = 0x80;
    } else {
        if (diff <= ((__OSBusClock / 4) / 1000) * 50 && type != 8) {
            OSRestoreInterrupts(enabled);
            return type;
        }
        if (diff <= ((__OSBusClock / 4) / 1000) * 75) {
            Type_802FCA34[chan] = 0x80;
        } else {
            Type_802FCA34[chan] = 0x80;
            type = 0x80;
        }
    }

    TypeTime_80640C88[chan] = __OSGetSystemTime();
    SITransfer(chan, &cmdTypeAndStatus, 1, &Type_802FCA34[chan], 3,
               GetTypeCallback_802093FC,
               (((__OSBusClock / 4) / 125000) * 65) / 8);
    OSRestoreInterrupts(enabled);
    return type;
}
