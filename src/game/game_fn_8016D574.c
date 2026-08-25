extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8020104C(int, void*, void*, int, float);
extern const char lbl_8024FF00[];

int fn_8016D574(void* state)
{
    int x;
    int y;
    float z;
    int flags;

    fn_8016A598(state);
    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }
    fn_8016A694(state, 1);
    x = (int)fn_8016A694(state, 2);
    y = (int)fn_8016A694(state, 3);
    z = (float)fn_8016A694(state, 4);
    flags = (int)fn_8016A694(state, 5);
    if (x != 0) {
        fn_8020104C(y, 0, (void*)x, flags, z);
    }
    return 0;
}
