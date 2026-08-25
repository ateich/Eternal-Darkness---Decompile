extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801441C0(int, int, int);
extern const char lbl_8024FF00[];

int fn_80176BA4(void* state)
{
    int first;
    int second;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    fn_801441C0(first, second, (int)fn_8016A694(state, 3));
    return 0;
}
