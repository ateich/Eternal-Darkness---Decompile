typedef unsigned short u16;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801FA454(int, u16);
extern const char lbl_8024FF00[];

int fn_8016E634(void* state)
{
    int first;
    u16 second;
    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }
    first = (int)fn_8016A694(state, 1);
    second = (u16)(int)fn_8016A694(state, 2);
    fn_801FA454(first, second);
    return 0;
}
