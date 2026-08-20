extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8020123C(int, int, int, int*);
extern const char lbl_8024FF00[];

int fn_8016D7AC(void* state)
{
    int values[4];
    int x;
    int y;

    if (fn_8016A598(state) != 4) {
        fn_80163BB4(state, lbl_8024FF00, 4, fn_8016A598(state));
        return 0;
    }
    x = (int)fn_8016A694(state, 1);
    y = (int)fn_8016A694(state, 2);
    values[0] = (int)fn_8016A694(state, 3);
    values[1] = (int)fn_8016A694(state, 4);
    if (x != 0) {
        fn_8020123C(y, 0, x, values);
    }
    return 0;
}
