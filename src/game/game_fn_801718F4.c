extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_80052310(int, void*);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_801718F4(void* state)
{
    int value;
    unsigned int result;
    void* text;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    text = fn_8016A784(state, 2);
    result = fn_80052310(value, text);
    fn_8016A830(state, result);
    return 1;
}
