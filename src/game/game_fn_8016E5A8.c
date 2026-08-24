extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801F898C(void*, int);
extern const char lbl_8024FF00[];
extern char lbl_8063CD18[];

int fn_8016E5A8(void* state)
{
    int value;
    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }
    value = (int)fn_8016A694(state, 1);
    fn_801F898C(lbl_8063CD18 + 0x110, value);
    return 0;
}
