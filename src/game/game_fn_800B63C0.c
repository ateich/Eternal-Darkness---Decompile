extern int lbl_8064C6BC[2];

extern int fn_800B6908(void);
extern void fn_800B2548(int, int);
extern int fn_800B1944(void);

void fn_800B63C0(int value, int status)
{
    int state = fn_800B6908();

    switch (status) {
    case -11:
        fn_800B2548(24, value);
        break;
    case -4:
        if (state == 0) {
            fn_800B2548(25, value);
        } else {
            fn_800B2548(71, value);
        }
        if (fn_800B1944() == 2) {
            lbl_8064C6BC[value] = 2;
        }
        break;
    case -14:
        fn_800B2548(70, value);
        break;
    case -10:
        fn_800B2548(69, value);
        break;
    case -3:
    case -1:
        fn_800B2548(68, value);
        break;
    case 0:
        break;
    default:
        fn_800B2548(67, value);
        break;
    }
}
