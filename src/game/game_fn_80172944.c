extern int fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_800460EC(void);
extern const char lbl_8024FF00[];
extern const double lbl_806506D8;

int fn_80172944(void* state)
{
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    if (fn_800460EC() != 0) {
        fn_8016A830(state, lbl_806506D8);
    } else {
        fn_8016A7D8(state);
    }
    return 1;
}
