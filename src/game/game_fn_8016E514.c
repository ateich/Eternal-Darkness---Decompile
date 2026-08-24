extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern int fn_80201BC8(void);
extern void fn_801F700C(int, int);
extern const char lbl_8024FF00[];

int fn_8016E514(void* state)
{
    int value;
    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }
    value = (int)fn_8016A694(state, 1);
    fn_80201814(value);
    fn_801F700C(2, fn_80201BC8());
    return 1;
}
