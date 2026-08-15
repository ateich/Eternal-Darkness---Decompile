extern void fn_800B7E44(int, int);
extern void fn_800B261C(int);
extern int fn_800AF7E4(int, int*);
extern void fn_8017B31C(void (*)(void));
extern void fn_800B19A4(void);
extern void fn_800B4B74(void);
extern void fn_800B2624(int, int, int, int, void (*)(void));
extern void fn_800B5D94(int);

void fn_800B5D10(int value)
{
    int output;

    fn_800B7E44(value, 1);
    fn_800B261C(1);
    switch (fn_800AF7E4(value, &output)) {
    case 1:
        fn_8017B31C(fn_800B19A4);
        fn_800B2624(1, value, 0, 0, fn_800B4B74);
        break;
    default:
        fn_800B5D94(value);
        break;
    }
}
