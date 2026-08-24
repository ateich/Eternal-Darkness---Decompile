extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_801A5CE0(void);
extern int fn_801A5D04(void);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_8016FEF8(void* state)
{
    int value;

    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    value = 0;
    if (fn_801A5CE0() != 0 || fn_801A5D04() != 0) {
        value = 1;
    }
    fn_8016A830(state, value);
    return 1;
}
