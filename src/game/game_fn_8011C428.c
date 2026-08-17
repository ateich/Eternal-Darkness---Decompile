extern int fn_800B193C(void);
extern void fn_800B267C(short);
extern void fn_80144C40(void);

void fn_8011C428(int value)
{
    if (fn_800B193C() != 0) {
        fn_800B267C((short)value);
    }
    fn_80144C40();
}
