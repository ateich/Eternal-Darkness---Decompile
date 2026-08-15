extern void fn_800B25AC(void);
extern void fn_800B3B90(int, int);
extern void fn_8017B074(int);
extern void fn_800B2548(int, int);

void fn_800B4A48(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800B3B90(value, 0);
        break;
    case 1:
    case 2:
        fn_8017B074(value);
        fn_800B2548(1, value);
        break;
    }
}
