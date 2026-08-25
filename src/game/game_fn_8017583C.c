typedef unsigned int u32;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void);
extern void fn_8012C62C(void*, int, u32*, u32*, u32*, int);
extern const char lbl_8024FF00[];
extern const u32 lbl_80651CB0;
extern const u32 lbl_80651CB4;
extern const u32 lbl_80651CB8;

int fn_8017583C(void* state)
{
    u32 first;
    u32 second;
    u32 third;
    void* runtime;
    void* object;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    runtime = fn_80201814(fn_8016A694(state, 1));
    if (runtime != 0) {
        object = fn_80201BC8();
        third = lbl_80651CB8;
        second = lbl_80651CB4;
        first = lbl_80651CB0;
        fn_8012C62C(object, 15, &first, &second, &third, 4);
    }
    return 0;
}
