typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

#pragma pack(4)
typedef struct Voice {
    u8 pad_000[0x34];
    u32 active;
    u8 pad_038[0xB4];
    u32 next;
    u8 pad_0F0[4];
    u32 index;
    u8 pad_0F8[0x18];
    u32 field_110;
    u64 field_114;
    u8 flag_11C;
    u8 pad_11D[0x2E7];
} Voice;
#pragma pack()

typedef struct HandleInfo {
    u8 pad_000[0xC];
    u32 first;
} HandleInfo;

extern u8 lbl_8064D3A0;
extern Voice* lbl_8064D3D0;
extern HandleInfo* fn_801C1038(u32);
extern void fn_801C106C(Voice*);
extern void fn_801C1BCC(Voice*);
extern void fn_801B9C98(u32);
extern void fn_801CC8C4(u32);

s32 fn_801C21E8(u32 handle)
{
    Voice* voice;
    s32 result = -1;
    u32 next;
    u32 slot;
    HandleInfo* info;

    if (lbl_8064D3A0 != 0) {
        if (handle != (u32)-1 && (info = fn_801C1038(handle)) != 0) {
            handle = info->first;
        } else {
            handle = -1;
        }
        while (handle != (u32)-1) {
            slot = (u8)handle;
            voice = &lbl_8064D3D0[slot];
            next = voice->next;
            if (handle == voice->index) {
                if (voice->active != 0) {
                    fn_801C106C(voice);
                    voice->field_114 &= 0xFFFFFFFFFFFFFFFCULL;
                    voice->field_110 = 0;
                    fn_801C1BCC(voice);
                }
                if (voice->flag_11C != 0) {
                    fn_801B9C98(slot);
                }
                fn_801CC8C4(slot);
                result = 0;
            }
            handle = next;
        }
    }
    return result;
}
