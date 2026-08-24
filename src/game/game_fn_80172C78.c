extern int lbl_8064D18C;
extern int fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];

int fn_80172C78(void* state)
{
    int value;

    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    value = lbl_8064D18C;
    fn_8016A830(state, value);
    return 1;
}
