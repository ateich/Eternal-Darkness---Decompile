extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern void* fn_80156948(int);
extern void fn_80153104(void*);
extern const char lbl_8024FF00[];

int fn_80174610(void* state)
{
    void* object;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    object = fn_80156948(fn_800F5C54(fn_8016A694(state, 1)));
    if (object != 0) {
        fn_80153104(object);
    }
    return 0;
}
