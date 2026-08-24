extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_800F5C54(double);
extern void fn_801A9964(int);
extern const char lbl_8024FF00[];

int fn_8017187C(void* state)
{
    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    fn_801A9964(fn_800F5C54(fn_8016A694(state, 1)));
    return 0;
}
