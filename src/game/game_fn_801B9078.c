typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8064D3CC;
extern u8 *lbl_8064D3D0;
extern u8 lbl_80619C20[];
extern void fn_801CD418(void);
extern void fn_801BA15C(void);

void fn_801B9078(int arg0)
{
    u32 old_flags = lbl_8064D3CC;
    switch (arg0) {
    case 0:
        lbl_8064D3CC |= 1;
        lbl_8064D3CC &= ~2;
        fn_801CD418();
        break;
    case 1:
        lbl_8064D3CC &= ~1;
        lbl_8064D3CC &= ~2;
        fn_801CD418();
        break;
    case 2:
        lbl_8064D3CC &= ~1;
        lbl_8064D3CC |= 2;
        fn_801CD418();
        break;
    }
    if (old_flags != lbl_8064D3CC) {
        u32 i = 0;
        int offset = 0;
        while (i < lbl_80619C20[0x210]) {
            *(unsigned long long *)(lbl_8064D3D0 + offset + 0x114) |= 0x2000000000000000ULL;
            i++;
            offset += 0x404;
        }
        fn_801BA15C();
    }
}
