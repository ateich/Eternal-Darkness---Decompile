typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Voice {
    u8 pad_000[0x34];
    u32 value_034;
    u8 pad_038[0xBC];
    u32 handle;
    u8 pad_0F8[0x24];
    u8 flag_11C;
    u8 flag_11D;
    u8 pad_11E[0x2E6];
} Voice;

extern Voice* lbl_8064D3D0;
extern u32 fn_801C1790(u8, u8, unsigned short, u8);
extern void fn_801C106C(Voice*);
extern u32 fn_801CC6DC(u32);
extern void fn_801CC8C4(u32);
extern void fn_801C0ACC(Voice*, s32);
extern void fn_801C1600(Voice*, u8);

u32 fn_801C1FE0(u8 group)
{
    u32 offset;
    u32 result;

    result = fn_801C1790(group, 0xFF, 0xFFFF, 1);

    if (result != (u32)-1) {
        offset = result * 0x404;
        lbl_8064D3D0[result].flag_11C = 1;
        lbl_8064D3D0[result].flag_11D = 1;
        fn_801C106C(&lbl_8064D3D0[result]);
        lbl_8064D3D0[result].handle = result | 0xFFFFFF00;
        if (fn_801CC6DC(result) != 0) {
            fn_801CC8C4(result);
        }
        fn_801C0ACC(&lbl_8064D3D0[result], 2);
        lbl_8064D3D0[result].value_034 = 0;
        fn_801C1600(&lbl_8064D3D0[result], group);
    }
    return result;
}
