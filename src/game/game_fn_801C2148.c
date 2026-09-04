typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

#pragma pack(4)
typedef struct Voice {
    u8 pad_000[0x34];
    u32 active;
    u8 pad_038[0xD8];
    u32 field_110;
    u64 field_114;
    u8 flag_11C;
    u8 pad_11D[0x2E7];
} Voice;
#pragma pack()

extern Voice* lbl_8064D3D0;
extern void fn_801C106C(Voice*);
extern void fn_801C1BCC(Voice*);
extern void fn_801B9C98(u32);
extern void fn_801CC8C4(u32);

void fn_801C2148(u32 index)
{
    Voice* voice;

    voice = &lbl_8064D3D0[index];
    if (voice->active != 0) {
        fn_801C106C(voice);
        voice->field_114 &= 0xFFFFFFFFFFFFFFFCULL;
        voice->field_110 = 0;
        fn_801C1BCC(voice);
    }
    if (voice->flag_11C != 0) {
        fn_801B9C98(index);
    }
    fn_801CC8C4(index);
}
