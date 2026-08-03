typedef unsigned int u32;

extern u32 lbl_8064C648;
extern u32 lbl_8064C630;
extern void fn_801A9A40(u32, u32, u32);

void fn_8001D56C(void)
{
    if (lbl_8064C648 + 0x80000000 == 0) {
        fn_801A9A40(2, lbl_8064C630, lbl_8064C630);
    }
}
