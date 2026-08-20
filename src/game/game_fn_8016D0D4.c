extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];
extern int lbl_8064CB54;

int fn_8016D0D4(void* state)
{
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }
    lbl_8064CB54 ^= 1;
    return 0;
}
