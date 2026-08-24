extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_801301B0(void*, int, int);
extern void fn_80130434(void*, int);
extern const char lbl_8024FF00[];

int fn_8016F1D0(void* state)
{
    void* object;
    int mode;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object = fn_80201BC8(fn_80201814((int)fn_8016A694(state, 1)));
    mode = (int)fn_8016A694(state, 2);
    if (mode != 0) {
        fn_801301B0(object, 0x20, 0);
    } else {
        fn_80130434(object, 1);
        fn_801301B0(object, 0, 0x20);
    }
    return 0;
}
