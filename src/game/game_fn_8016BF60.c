extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_801B0B30(int);
extern int fn_801AF924(void);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_8016BF60(void* state)
{
    int result;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    fn_801B0B30((int)fn_8016A694(state, 1));
    result = fn_801AF924();
    fn_8016A830(state, result);
    return 1;
}
