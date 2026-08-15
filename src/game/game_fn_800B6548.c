extern void fn_800B2548(int, int);

void fn_800B6548(int value, int status)
{
    switch (status) {
    case -11:
        fn_800B2548(28, value);
        break;
    case -4:
        fn_800B2548(29, value);
        break;
    case -3:
    case -1:
        fn_800B2548(77, value);
        break;
    case -10:
        fn_800B2548(78, value);
        break;
    case -14:
        fn_800B2548(79, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(80, value);
        break;
    }
}
