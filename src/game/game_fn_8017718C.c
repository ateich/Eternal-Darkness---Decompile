extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800FBFB0(void);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_8017718C(void* state)
{
    int divisor;
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    divisor = (int)fn_8016A694(state, 1);
    value = (int)fn_800FBFB0() % divisor;
    fn_8016A830(state, (double)value);
    return 1;
}
