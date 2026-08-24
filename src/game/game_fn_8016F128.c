extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_8012B344(void*);
extern const char lbl_8024FF00[];

int fn_8016F128(void* state)
{
    void* handle;
    void* object;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    handle = fn_80201814((int)fn_8016A694(state, 1));
    object = handle != 0 ? fn_80201BC8(handle) : 0;
    if (handle != 0 && object != 0) {
        fn_8012B344(object);
    }
    return 0;
}
