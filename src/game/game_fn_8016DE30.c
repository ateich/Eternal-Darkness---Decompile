extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern void fn_801F6370(void*, int);
extern const char lbl_8024FF00[];

int fn_8016DE30(void* state)
{
    void* object;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object = (void *)fn_800F5C54(fn_8016A694(state, 1));
    fn_801F6370(object, (int)fn_8016A694(state, 2));
    return 0;
}
