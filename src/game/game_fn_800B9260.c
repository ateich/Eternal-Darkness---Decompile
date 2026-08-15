extern void *lbl_8064C9F0;
extern void *lbl_8064C9F4;
extern void fn_801E5FB0(void *);
extern void fn_800B8F6C(void);

void fn_800B9260(void)
{
    if (lbl_8064C9F0 != 0) {
        fn_801E5FB0(lbl_8064C9F0);
    }
    if (lbl_8064C9F4 != 0) {
        fn_801E5FB0(lbl_8064C9F4);
    }
    fn_800B8F6C();
}
