typedef signed int s32;
typedef unsigned int u32;

typedef void (*SITypeCallback)(s32 chan, u32 type);

extern u32 Type_802FCA34[4];
extern SITypeCallback lbl_80640CC8[4][4];

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 enabled);
extern u32 SIGetType(s32 chan);

u32 fn_80209858(s32 chan, SITypeCallback callback)
{
    u32 enabled;
    u32 type;
    s32 i;

    enabled = OSDisableInterrupts();
    type = SIGetType(chan);

    if (Type_802FCA34[chan] & 0x80) {
        for (i = 0; i < 4; i++) {
            if (lbl_80640CC8[chan][i] == callback) {
                break;
            }
            if (lbl_80640CC8[chan][i] == 0) {
                lbl_80640CC8[chan][i] = callback;
                break;
            }
        }
    } else {
        callback(chan, type);
    }

    OSRestoreInterrupts(enabled);
    return type;
}
