extern void fn_800B2548(int, int);

void fn_800B611C(int value, int status)
{
    switch (status) {
    case -11:
        fn_800B2548(19, value);
        break;
    case -4:
        fn_800B2548(20, value);
        break;
    case -3:
    case -1:
        fn_800B2548(54, value);
        break;
    case -10:
        fn_800B2548(55, value);
        break;
    case -14:
        fn_800B2548(56, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(57, value);
        break;
    }
}
