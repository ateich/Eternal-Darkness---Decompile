extern int fn_8016A598(void*);
extern float fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801AD734(int);
extern const char lbl_8024FF00[];
extern const char lbl_802503C8[];

int fn_8017230C(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    if (value < 0) {
        fn_80163BB4(state, lbl_802503C8, value);
    }
    fn_801AD734(value);
    return 0;
}
