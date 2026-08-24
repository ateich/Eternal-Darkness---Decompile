extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int lbl_8064D1C4;
extern const char lbl_8024FF00[];

int fn_80170C84(void* state)
{
    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    lbl_8064D1C4 = fn_8016A694(state, 1);
    return 0;
}
