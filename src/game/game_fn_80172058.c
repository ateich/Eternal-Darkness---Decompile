extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801AD4B4(int, int, int, unsigned short);
extern const char lbl_8024FF00[];
extern unsigned int lbl_8064D1BC;

int fn_80172058(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    fn_801AD4B4(value, 0, 0, (unsigned short)lbl_8064D1BC);
    return 0;
}
