extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_80204888(int);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_80176DF4(void* state)
{
    int id;
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    id = (int)fn_8016A694(state, 1);
    value = fn_80204888(id);
    fn_8016A830(state, (double)value);
    return 1;
}
