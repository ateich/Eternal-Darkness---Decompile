extern int fn_8016A598(void*);
extern void* fn_8016A784(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];

int fn_80176FA0(void* state)
{
    unsigned int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = *(unsigned int*)((char*)fn_8016A784(state, 1) + 0x2C);
    fn_8016A830(state, (double)value);
    return 1;
}
