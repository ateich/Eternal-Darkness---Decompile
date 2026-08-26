extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54(double);
extern void fn_8015C8A4(int, int);
extern const char lbl_8024FF00[];

int fn_8016C7C4(void* state)
{
    switch (fn_8016A598(state)) {
    case 2: {
        int value = (int)fn_8016A694(state, 1);
        fn_8015C8A4(fn_800F5C54(fn_8016A694(state, 2)), value);
        break;
    }
    default:
        if (fn_8016A598(state) != 1) {
            fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
            return 0;
        }
        fn_8015C8A4(1, (int)fn_8016A694(state, 1));
        break;
    }
    return 0;
}
