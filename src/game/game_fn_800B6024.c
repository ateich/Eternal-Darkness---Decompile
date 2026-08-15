extern int fn_800B1944(void);
extern void fn_800B2548(int, int);

void fn_800B6024(int value, int status)
{
    int state = fn_800B1944();

    switch (status) {
    case -8:
        if (state == 0 || state == 1) {
            fn_800B2548(32, value);
        } else {
            fn_800B2548(30, value);
        }
        break;
    case -9:
        if (state == 0 || state == 1) {
            fn_800B2548(33, value);
        } else {
            fn_800B2548(31, value);
        }
        break;
    case -7:
        fn_800B2548(50, value);
        break;
    case -3:
    case -1:
        fn_800B2548(51, value);
        break;
    case -12:
        fn_800B2548(52, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(53, value);
        break;
    }
}
