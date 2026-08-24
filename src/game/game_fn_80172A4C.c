extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8015C7D8(int);
extern const char lbl_8024FF00[];

int fn_80172A4C(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = fn_8016A694(state, 1);
    fn_8015C7D8(value);
    return 0;
}
