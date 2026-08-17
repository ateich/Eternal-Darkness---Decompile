extern int lbl_8064CE6C;

extern int fn_800B193C(void);
extern void fn_800B267C(short);
extern void fn_80144C40(void);
extern void fn_801E8B6C(int, int);

void fn_8011CFF8(int value)
{
    if (fn_800B193C() != 0) {
        fn_800B267C((short)value);
    } else {
        fn_801E8B6C(lbl_8064CE6C, value);
    }
    fn_80144C40();
}
