extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801F7034(void*, int);
extern const char lbl_8024FF00[];
extern unsigned char lbl_8063CD18[];

int fn_80170658(void* state)
{
    unsigned char* target;

    target = lbl_8063CD18 + 0x110;
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    fn_801F7034(target, 0);
    return 0;
}
