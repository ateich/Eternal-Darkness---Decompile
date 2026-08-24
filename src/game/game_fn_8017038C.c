extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern const char lbl_8024FF00[];
extern float lbl_8063D400[];

int fn_8017038C(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    lbl_8063D400[2] -= value;
    return 0;
}
