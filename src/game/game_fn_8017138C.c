extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_800473AC(void);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];
extern const double lbl_806506A8;

int fn_8017138C(void* state)
{
    int value;

    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    value = fn_800473AC();
    fn_8016A830(state, value);
    return 1;
}
