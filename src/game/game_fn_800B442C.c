extern void fn_800B25AC(void);
extern int fn_800B1944(void);
extern void fn_800B6840(int);
extern void fn_800B669C(int, int);

void fn_800B442C(int value)
{
    fn_800B25AC();
    if (fn_800B1944() != 2) {
        fn_800B6840(value);
    } else {
        fn_800B669C(value, 0);
    }
}
