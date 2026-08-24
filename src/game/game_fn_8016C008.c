extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_801B05E8(int, int, int, int, int, int, int, int);
extern const char lbl_8024FF00[];

int fn_8016C008(void* state)
{
    int first;
    int second;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    fn_801B05E8(first, second, 4, 0, 0, 5, 0, 0);
    return 0;
}
