extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern int fn_801B002C(int, int, int, int, int);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_8016C164(void* state)
{
    int first;
    int result;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    result = fn_801B002C(first, (int)fn_8016A694(state, 2), 1, 0, 0);
    fn_8016A830(state, result);
    return 1;
}
