extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_801290D0(void*);
extern void fn_80128F74(void*, int);
extern void fn_801A5C30(int);
extern const char lbl_8024FF00[];
extern void* lbl_8064C4E4;

int fn_8016FE4C(void* state)
{
    int value;
    int flags;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    if (value == 0) {
        if (lbl_8064C4E4 != 0) {
            flags = fn_801290D0(lbl_8064C4E4);
            fn_80128F74(lbl_8064C4E4, flags | 4);
        }
    }
    fn_801A5C30(value);
    return 0;
}
