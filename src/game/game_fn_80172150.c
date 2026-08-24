extern int fn_8016A598(void*);
extern float fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801AD6F4(int);
extern const char lbl_8024FF00[];
extern const char lbl_80250358[];

int fn_80172150(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    if (value != 0 && value != 1) {
        fn_80163BB4(state, lbl_80250358, value);
    }
    fn_801AD6F4(value);
    return 0;
}
