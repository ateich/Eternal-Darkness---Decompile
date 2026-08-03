typedef int s32;
typedef unsigned int u32;

extern s32 lbl_8064A998;
extern u32 lbl_8064C648;
extern s32 lbl_8064C670;
extern char lbl_80302400[];

extern void fn_8001D5A8(void);
extern void fn_800AFC30(void*);

void fn_8001DA18(void)
{
    if (lbl_8064C648 == 0x80000000) {
        lbl_8064C648 = 0;
        fn_8001D5A8();
    }
    if (lbl_8064C670 != 0 && lbl_8064A998 != 0) {
        fn_800AFC30(lbl_80302400);
        lbl_8064C670 = 0;
    }
}
