extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_801F75FC(int, int, float);
extern const char lbl_8024FF00[];

int fn_801704F8(void* state)
{
    int first;
    int second;
    int third;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    third = (int)fn_8016A694(state, 3);
    fn_801F75FC(first, second, third);
    return 0;
}
