extern void fn_800B25AC(void);
extern int fn_8017B32C(int);
extern void fn_800B2548(int, int);

void fn_800B4938(int value)
{
    fn_800B25AC();
    if (fn_8017B32C(value) == 0) {
        fn_800B2548(1, value);
    } else {
        fn_800B2548(10, value);
    }
}
