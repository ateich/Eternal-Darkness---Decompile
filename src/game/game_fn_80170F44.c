extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern int fn_8015C4A4(int, int);
extern void* fn_80158ABC(int, int, void*);
extern void fn_8016A970(void*, void*, int);
extern const char lbl_8024FF00[];
extern const char lbl_8025009C[];

int fn_80170F44(void* state)
{
    int handle;
    int index;
    void* result;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    handle = fn_800F5C54(fn_8016A694(state, 1));
    index = fn_8015C4A4(handle, 2);
    if (index != -1) {
        result = fn_80158ABC(index, 2, 0);
        fn_8016A970(state, result, 0);
    } else {
        fn_80163BB4(state, lbl_8025009C, handle);
        fn_8016A970(state, 0, 0);
    }
    return 1;
}
