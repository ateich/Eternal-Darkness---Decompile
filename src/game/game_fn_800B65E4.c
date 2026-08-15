extern void fn_8017B074(int);
extern void fn_800B7E44(int, int);
extern int fn_800AF7E4(int, int*);
extern void fn_800B261C(int);
extern void fn_800B19A4(void);
extern void fn_8017B31C(void (*)(void));
extern void fn_800B4B74(void);
extern void fn_8017BBD0(int, int, int, int, void (*)(void));
extern void fn_800B2548(int, int);
extern void fn_800B5E90(int, int);

void fn_800B65E4(int value)
{
    int output;

    fn_8017B074(value);
    fn_800B7E44(value, 1);
    switch (fn_800AF7E4(value, &output)) {
    case 1:
        fn_800B261C(1);
        fn_8017B31C(fn_800B19A4);
        fn_8017BBD0(1, value, 0, 0, fn_800B4B74);
        break;
    case -2:
        fn_800B2548(40, value);
        break;
    case -1:
        fn_800B5E90(value, output);
        break;
    }
}
