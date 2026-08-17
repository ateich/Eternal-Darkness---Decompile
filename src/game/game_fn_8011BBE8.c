extern int lbl_8064CE44;
extern int lbl_8064CDC8;

extern int fn_8017BB60(void);
extern int fn_800B9460(void);
extern int fn_800B2E60(void);
extern void fn_8014C23C(int, int, int);
extern void fn_8011BB48(void);
extern void *fn_80144710(int, int, int);
extern void fn_8010F418(void);
extern void fn_8010AD7C(void);
extern int fn_801A98F4(int, int);
extern void fn_80144C40(void);

void fn_8011BBE8(void)
{
    if (fn_8017BB60() == 0 && (lbl_8064CE44 & 2) == 0 && fn_800B9460() == 0 &&
        fn_800B2E60() != 0) {
        if ((lbl_8064CE44 & 8) != 0) {
            fn_8014C23C(0, 0, 0);
            lbl_8064CE44 = 0;
        }
        fn_8011BB48();
        if (fn_80144710(0x1000, 0, 0) != 0) {
            lbl_8064CDC8 = 2;
        } else if (fn_80144710(0x1000000, 0, 0) != 0) {
            fn_8010F418();
            fn_801A98F4(495, 50);
        } else {
            fn_8010AD7C();
            fn_801A98F4(495, 50);
        }
    }
    fn_80144C40();
}
