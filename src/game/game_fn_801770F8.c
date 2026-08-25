extern int fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_801F99B8(void*);
extern const char lbl_8024FF00[];
extern char lbl_8063CD18[];

int fn_801770F8(void* state)
{
    unsigned int value;

    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    value = fn_801F99B8(*(void**)(lbl_8063CD18 + 0x18C));
    fn_8016A830(state, (double)value);
    return 1;
}
