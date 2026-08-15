extern void fn_800B2548(int, int);

void fn_800B5F78(int value, int status)
{
    switch (status) {
    case -6:
        fn_800B2548(16, value);
        break;
    case -11:
        fn_800B2548(17, value);
        break;
    case -4:
        fn_800B2548(18, value);
        break;
    case -14:
        fn_800B2548(49, value);
        break;
    case -10:
        fn_800B2548(48, value);
        break;
    case -3:
    case -1:
        fn_800B2548(47, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(46, value);
        break;
    }
}
