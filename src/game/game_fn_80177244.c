extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801F6FFC(void*);
extern const char lbl_8024FF00[];
extern char lbl_8063CD18[];
extern char lbl_8063C6B8[];

int fn_80177244(void* state)
{
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    fn_801F6FFC(lbl_8063CD18 + 0x198);
    fn_801F6FFC(lbl_8063C6B8 + 0x198);
    return 1;
}
