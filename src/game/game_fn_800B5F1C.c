extern void fn_800B2548(int, int);

void fn_800B5F1C(int value, int status)
{
    switch (status) {
    case -3:
    case -1:
        fn_800B2548(44, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(45, value);
        break;
    }
}
