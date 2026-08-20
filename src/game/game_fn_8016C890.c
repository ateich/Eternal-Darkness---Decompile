extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void* fn_80201814(int);
extern void fn_80201D34(void*, int);
extern void fn_80201D1C(void*, int);
extern void fn_8020123C(int, int, int, int);
extern const char lbl_8024FF00[];

int fn_8016C890(void* state)
{
    void* object;
    int other;
    int value;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }
    value = (int)fn_8016A694(state, 1);
    other = (int)fn_8016A694(state, 2);
    object = fn_80201814(value);
    if (object != 0) {
        fn_80201D34(object, other);
        fn_80201D1C(object, 1);
        fn_8020123C(0x3B, value, value, 0);
    }
    return 0;
}
