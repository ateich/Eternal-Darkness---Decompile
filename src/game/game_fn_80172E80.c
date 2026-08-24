extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8020B344(void*);
extern void* lbl_8064C3C8;
extern const char lbl_8024FF00[];

int fn_80172E80(void* state)
{
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    fn_8020B344(lbl_8064C3C8);
    return 0;
}
