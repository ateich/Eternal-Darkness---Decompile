extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_800471F8(void);
extern void fn_801AD734(int);
extern void fn_801AD770(unsigned short, int);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_801719B4(void* state)
{
    int result;
    int arg2;
    int arg4;
    int arg1;
    int arg3;
    int arg5;

    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }

    arg1 = (int)fn_8016A694(state, 1);
    arg2 = (int)fn_8016A694(state, 2);
    arg3 = (int)fn_8016A694(state, 3);
    arg4 = (int)fn_8016A694(state, 4);
    arg5 = (int)fn_8016A694(state, 5);
    result = fn_800471F8();
    if (result != 0) {
        if (arg1 != 0) {
            fn_801AD734(arg1);
        }
        fn_801AD770((unsigned short)arg2, arg5);
        fn_801AD734(arg3);
        fn_801AD770((unsigned short)arg4, arg5);
    }

    fn_8016A830(state, result);
    return 1;
}
