extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_801B0CA4(int, int);
extern const char lbl_8024FF00[];

int fn_8016C668(void* state)
{
    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    fn_801B0CA4(-1, (int)fn_8016A694(state, 1));
    return 0;
}
