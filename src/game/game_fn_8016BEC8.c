extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_801A9DCC(int, int, int);
extern const char lbl_8024FF00[];

int fn_8016BEC8(void* state)
{
    int amount;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    amount = (int)fn_8016A694(state, 1);
    fn_801A9DCC(0, amount == 1 ? 25 : 100, 10);
    return 0;
}
