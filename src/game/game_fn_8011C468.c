extern int lbl_8064CDD0;

extern int fn_800B193C(void);
extern void fn_800B2AE8(void);
extern unsigned int fn_80144470(int);
extern void fn_80144430(int, unsigned int);
extern void fn_80144C40(void);
extern int fn_801A98F4(int, int);

void fn_8011C468(void)
{
    unsigned int active;

    if (fn_800B193C() != 0) {
        fn_800B2AE8();
    } else {
        active = fn_80144470(1);
        fn_80144430(1, active ^ 1);
        if (active != 0) {
            lbl_8064CDD0 = 30;
        }
        fn_801A98F4(546, 100);
    }
    fn_80144C40();
}
