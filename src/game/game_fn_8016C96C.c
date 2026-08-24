extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void *fn_80201814();
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);
extern const char lbl_8024FF00[];

int fn_8016C96C(void* state)
{
    void* object;
    int second;
    int first;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }
    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    object = fn_80201814(first);
    if (object != 0) {
        fn_80201D2C(object, second);
        fn_80201D14(object, 1);
    }
    return 0;
}
