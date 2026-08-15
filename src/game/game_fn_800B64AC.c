extern void fn_800B2548(int, int);

void fn_800B64AC(int value, int status)
{
    switch (status) {
    case -11:
        fn_800B2548(27, value);
        break;
    case -4:
        fn_800B2548(76, value);
        break;
    case -14:
        fn_800B2548(75, value);
        break;
    case -10:
        fn_800B2548(74, value);
        break;
    case -3:
    case -1:
        fn_800B2548(73, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(72, value);
        break;
    }
}
