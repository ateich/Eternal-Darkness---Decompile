typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern char lbl_802515C0[];
extern u32 lbl_8064D280;
extern u32 lbl_8064D284;
extern u8 lbl_8064D288;
extern void* lbl_8064D28C;

extern void* fn_801FEA8C(u32, u32, const char*, u32);
extern void* fn_8017CCD8(void*, u32, u32);

void fn_801A83A4(u32 count)
{
    void* allocation = fn_801FEA8C((u16)count * 0x1C, 1, lbl_802515C0, 0x75);
    lbl_8064D28C = fn_8017CCD8(allocation, 0x1C, count);
    lbl_8064D288 = 0;
    lbl_8064D280 = 0;
    lbl_8064D284 = 0;
}
