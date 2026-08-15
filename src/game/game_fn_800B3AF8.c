extern void fn_800B25AC(void);
extern int fn_8017B32C(int);
extern int fn_800BC028(int);
extern void fn_800B2548(int, int);
extern void fn_800B4660(int, int);
extern void fn_800B6840(int);

void fn_800B3AF8(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        if (fn_8017B32C(value) == 0) {
            if (fn_800BC028(value) != 0) {
                fn_800B2548(0x56, value);
            }
        } else {
            fn_800B4660(value, 0);
        }
        break;
    case 1:
    case 2:
        fn_800B6840(value);
        break;
    }
}
