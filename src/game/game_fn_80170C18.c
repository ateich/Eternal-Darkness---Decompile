extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern int lbl_8064D1BC;
extern int lbl_8064D1C4;
extern const char lbl_8024FF00[];

int fn_80170C18(void* state)
{
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    lbl_8064D1C4 = lbl_8064D1BC;
    return 0;
}
