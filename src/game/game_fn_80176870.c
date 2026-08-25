extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801F0294(float, int);
extern const char lbl_8024FF00[];

int fn_80176870(void* state)
{
    float value;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }
    value = (float)fn_8016A694(state, 1);
    fn_801F0294(value, (int)fn_8016A694(state, 2));
    return 0;
}
