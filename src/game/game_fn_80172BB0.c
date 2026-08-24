extern int fn_8016A598(void*);
extern float fn_8016A694(void*, int);
extern int fn_800F5C54(float);
extern int fn_802066E0(int, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];

int fn_80172BB0(void* state)
{
    int first;
    int second;
    int result;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = fn_800F5C54(fn_8016A694(state, 2));
    result = fn_802066E0(first, second);
    fn_8016A830(state, result);
    return 1;
}
