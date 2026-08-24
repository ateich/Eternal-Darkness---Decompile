extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_800F5C54(double);
extern void fn_801F64A8(void*, int, int);
extern const char lbl_8024FF00[];

int fn_8016DCB0(void* state)
{
    int first;
    void* object;
    int second;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    object = fn_800F5C54(fn_8016A694(state, 1));
    first = (int)fn_8016A694(state, 2);
    second = (int)fn_8016A694(state, 3);
    fn_801F64A8(object, first, second);
    return 1;
}
