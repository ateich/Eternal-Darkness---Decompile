extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern void fn_801E79A0(void*, int);
extern void fn_801E7974(void*, int);
extern void* lbl_8064C4E0;
extern const char lbl_8024FF00[];
extern const char lbl_802501CC[];

int fn_80170D04(void* state)
{
    int handle;
    int mode;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    handle = fn_800F5C54(fn_8016A694(state, 1));
    mode = fn_8016A694(state, 2);
    if (mode != 0 && mode != 1) {
        fn_80163BB4(state, lbl_802501CC, mode);
    }

    if (mode == 0) {
        fn_801E79A0(lbl_8064C4E0, handle);
    } else {
        fn_801E7974(lbl_8064C4E0, handle);
    }
    return 0;
}
