extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801ACACC(int, int, int, int);
extern const char lbl_8024FF00[];

int fn_80171AF0(void* state)
{
    int arg1;
    int arg2;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    arg1 = (int)fn_8016A694(state, 1);
    arg2 = (int)fn_8016A694(state, 2);
    fn_801ACACC(arg1, arg2, 0, (int)fn_8016A694(state, 3));
    return 0;
}
