typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* lbl_8064D220;
extern u32 lbl_8064D21C;
extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern u8 lbl_80606348[];
extern u8 lbl_80607120[];
extern u8 lbl_80607130[];
extern char lbl_802510F8[];

extern u32 fn_8017FFA8(void);
extern void* fn_801FEA8C(u32, u32, const char*, u32);
extern void* fn_8017CCD8(void*, u32, u32);
extern void fn_801807B0(void*, u32, u32, u32);
extern void fn_801816D4(void);

void fn_80180014(u32 first, u32 unused, u32 third, u32 count)
{
    u32 size = fn_8017FFA8();

    lbl_8064D220 = fn_801FEA8C(size * (u16)count, 1, lbl_802510F8, 0x32D);
    lbl_8064D21C = (u16)count;
    lbl_8064D238 = fn_8017CCD8(lbl_8064D220, size, count);

    if ((u16)first != 0) {
        *(void**)(lbl_80606334 + 0x10) = lbl_80607120;
        fn_801807B0(lbl_80606334, first, 0x20, 4);
    }
    if ((u16)third != 0) {
        *(void**)(lbl_80606348 + 0x10) = lbl_80607130;
        fn_801807B0(lbl_80606348, third, 1, 4);
    }
    fn_801816D4();
}
