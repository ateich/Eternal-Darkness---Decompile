extern int fn_8016A598(void*);
extern float fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801AC350(signed char, int, int);
extern const char lbl_8024FF00[];
extern const char lbl_80250414[];

int fn_80172610(void* state)
{
    int value;
    signed char clamped;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    clamped = (value > 0 ? value : 0) > 0x7F
                  ? 0x7F
                  : (value > 0 ? value : 0);
    if (value != clamped) {
        fn_80163BB4(state, lbl_80250414, value);
    }
    fn_801AC350(clamped, 0, 0);
    return 0;
}
