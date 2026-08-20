extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void* fn_80201814(int);
extern int fn_80201B64(void*);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_8016D1F8(void* state)
{
    int result = -1;
    void* object;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }
    object = fn_80201814((int)fn_8016A694(state, 1));
    if (object != 0) {
        result = fn_80201B64(object);
    }
    fn_8016A830(state, (double)result);
    return 1;
}
