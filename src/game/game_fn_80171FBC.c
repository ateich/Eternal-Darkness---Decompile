extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801AD46C(unsigned char*, unsigned char*);
extern void fn_801AD4B4(int, int, int, int);
extern const char lbl_8024FF00[];

int fn_80171FBC(void* state)
{
    int value;
    unsigned char arg0;
    unsigned char arg1;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    fn_801AD46C(&arg0, &arg1);
    fn_801AD4B4(value, 0, 0, 0);
    return 0;
}
