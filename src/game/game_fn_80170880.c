extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_8016A970(void*, void*, int);
extern const char lbl_8024FF00[];
extern const char lbl_8025014C[];
extern void* lbl_8064C4E4;

int fn_80170880(void* state)
{
    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    switch ((int)fn_8016A694(state, 1)) {
    case 0:
        fn_8016A970(state, lbl_8064C4E4, 0);
        return 1;
    case 1:
        fn_8016A970(state, 0, 0);
        return 1;
    default:
        fn_80163BB4(state, lbl_8025014C, (int)fn_8016A694(state, 1));
        fn_8016A970(state, 0, 0);
        return 1;
    }
}
