extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern int fn_800467F0(int, int);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];

int fn_80175E64(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }
    value = fn_8016A694(state, 1);
    value = fn_800467F0(value, 0);
    fn_8016A830(state, (double)value);
    return 1;
}
