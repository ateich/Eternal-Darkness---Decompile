extern int fn_80201B44(void);
extern void* fn_80201814(void);
extern int fn_80201EB8(void);
extern int fn_80200F3C(int, int);
extern int fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];
extern const double lbl_806506A8;

int fn_8017553C(void* state)
{
    int first;
    int second;
    int result;

    first = fn_80201B44();
    fn_80201814();
    second = fn_80201EB8();
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    result = fn_80200F3C(first, second);
    fn_8016A830(state, result);
    return 1;
}
