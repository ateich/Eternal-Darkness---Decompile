extern int fn_80201B44(void*);
extern void* fn_80201814(int);
extern int fn_80201EB8(void*);
extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80200EAC(int, int, int, int, float);
extern const char lbl_8024FF00[];
extern const float lbl_806506B8;

int fn_8016CDA0(void* state)
{
    int first = fn_80201B44(state);
    int second = fn_80201EB8(fn_80201814(first));

    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }
    fn_80200EAC(0x39, first, 0, second, lbl_806506B8);
    return 0;
}
