extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80046CE4(int);
extern void fn_80046DB4(int);
extern const char lbl_8024FF00[];
extern const double lbl_806506D0;

int fn_801749A8(void* state)
{
    int value;
    double second_value;

    switch (fn_8016A598(state)) {
    case 2:
        value = fn_8016A694(state, 1);
        second_value = fn_8016A694(state, 2);
        if (second_value == lbl_806506D0) {
            fn_80046CE4(value);
        } else {
            fn_80046DB4(value);
        }
        break;
    case 1:
        fn_80046CE4(fn_8016A694(state, 1));
        break;
    default:
        if (fn_8016A598(state) != 1) {
            fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
            return 0;
        }
        break;
    }
    return 0;
}
