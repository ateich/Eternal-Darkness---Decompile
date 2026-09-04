typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Voice {
    u8 pad_000[0xF4];
    u32 index;
    u8 pad_0F8[0x24];
    u8 flag_11C;
    u8 pad_11D[0x2E7];
} Voice;

extern Voice* lbl_8064D3D0;
extern u32 fn_801CC6DC(u32);
extern void fn_801CC8C4(u32);
extern void fn_801C1BCC(Voice*);

void fn_801C20C8(u32 index)
{
    u32 offset;

    if (index != (u32)-1) {
        if (fn_801CC6DC(index) != 0) {
            fn_801CC8C4(index);
        }
        offset = index * 0x404;
        lbl_8064D3D0[index].index = index;
        fn_801C1BCC(&lbl_8064D3D0[index]);
        lbl_8064D3D0[index].flag_11C = 0;
    }
}
