extern int fn_8016A598(void*);
extern float fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80045A24(int, int);
extern const char lbl_8024FF00[];

int fn_8017288C(void* state)
{
    int first;
    int flags = 0;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    if ((int)fn_8016A694(state, 2) == 1) {
        flags |= 1;
    }
    fn_80045A24(first, flags);
    return 0;
}
