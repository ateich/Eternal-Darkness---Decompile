extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801EB2FC(int);
extern const char lbl_8024FF00[];

int fn_80176F34(void* state)
{
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    fn_801EB2FC(1);
    return 1;
}
