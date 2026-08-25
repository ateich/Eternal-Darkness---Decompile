extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_801A7DEC(int);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];
extern const char lbl_80250450[];

int fn_80172D04(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    if (value > 1 || value < 0) {
        fn_80163BB4(state, lbl_80250450, value);
    }
    fn_801A7DEC(value);
    return 0;
}
