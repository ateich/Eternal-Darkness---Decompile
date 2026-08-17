extern int fn_800B193C(void);
extern void fn_800B2778(short);
extern void fn_80144C40(void);

void fn_8011D5C0(int value)
{
    if (fn_800B193C() != 0) {
        fn_800B2778((short)-value);
    }
    fn_80144C40();
}
