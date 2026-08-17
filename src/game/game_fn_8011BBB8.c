extern int lbl_8064CE44;
extern void fn_800B2778(void);
extern void fn_80144C40(void);

void fn_8011BBB8(void)
{
    if ((lbl_8064CE44 & 2) == 0) {
        fn_800B2778();
    }
    fn_80144C40();
}
