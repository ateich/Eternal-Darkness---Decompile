extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_802019EC(int, void*);
extern unsigned long long fn_8020123C(int, int, void*, int);
extern const char lbl_8024FF00[];
extern void* lbl_8064D18C;

int fn_801714BC(void* state)
{
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    value = fn_8016A694(state, 1);
    if (value != 0) {
        void* object = fn_802019EC(value, lbl_8064D18C);
        fn_8020123C(0x13, 0, object, 0);
    }
    return 0;
}
