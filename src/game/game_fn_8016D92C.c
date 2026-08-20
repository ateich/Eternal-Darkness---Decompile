extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, int, ...);
extern const char lbl_8024FF00[];
extern int lbl_8064D6E0;
extern int lbl_8064D6DC;

int fn_8016D92C(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    if (value != lbl_8064D6E0) {
        lbl_8064D6E0 = value;
        lbl_8064D6DC = 1;
    }
    return 0;
}
