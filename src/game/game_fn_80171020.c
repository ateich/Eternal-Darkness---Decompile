extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_800F5C54(double);
extern int fn_8015C4A4(int, int);
extern void* fn_80158ABC(int, int, void*);
extern void fn_8016A830(void*, double);
extern void fn_8016A970(void*, void*, int);
extern const char lbl_8024FF00[];
extern const char lbl_80250200[];
extern const float lbl_806506C4;

int fn_80171020(void* state)
{
    int handle;
    int index;
    float value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    handle = fn_800F5C54(fn_8016A694(state, 1));
    index = fn_8015C4A4(handle, 2);
    if (index != -1) {
        fn_80158ABC(index, 2, &value);
        fn_8016A830(state, lbl_806506C4 * value);
    } else {
        fn_80163BB4(state, lbl_80250200, handle);
        fn_8016A970(state, 0, 0);
    }
    return 1;
}
