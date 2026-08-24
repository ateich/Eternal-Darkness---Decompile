typedef signed short s16;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016B0B4(s16, int);
extern int lbl_8064D1BC;
extern const char lbl_80250164[];

int fn_80170B5C(void* state)
{
    s16 first = lbl_8064D1BC;
    int second;

    switch (fn_8016A598(state)) {
    case 2:
        first = fn_8016A694(state, 2);
    case 1:
        second = fn_8016A694(state, 1);
        break;
    default:
        fn_80163BB4(state, lbl_80250164, fn_8016A598(state));
        return 0;
    }

    fn_8016B0B4(first, second);
    return 0;
}
