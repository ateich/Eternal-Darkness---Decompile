extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern int fn_801E79FC(void*, int);
extern void fn_8016A830(void*, double);
extern void* lbl_8064C4E0;
extern const char lbl_8024FF00[];

int fn_80170DF4(void* state)
{
    int handle;
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    handle = fn_800F5C54(fn_8016A694(state, 1));
    value = fn_801E79FC(lbl_8064C4E0, handle);
    fn_8016A830(state, value);
    return 1;
}
