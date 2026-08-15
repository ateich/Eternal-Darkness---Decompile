extern void fn_800B2548(int, int);

void fn_800B61B8(int value, int status)
{
    switch (status) {
    case -3:
    case -1:
        fn_800B2548(59, value);
        break;
    case -4:
        fn_800B2548(61, value);
        break;
    case -10:
        fn_800B2548(60, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(58, value);
        break;
    }
}
