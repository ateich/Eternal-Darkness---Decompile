extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801B2380(int);
extern void fn_801B2348(int);
extern const char lbl_8024FF00[];
extern const char lbl_80250404[];

int fn_801723B8(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    if (value == 1) {
        fn_801B2380(0);
    } else if (value == 0) {
        fn_801B2348(0);
    } else {
        fn_80163BB4(state, lbl_80250404, value);
    }
    return 0;
}
