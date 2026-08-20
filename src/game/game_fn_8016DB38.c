typedef unsigned short u16;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, int, ...);
extern void* fn_800F5C54(double);
extern void fn_8016D9C0(unsigned int, u16*, u16*);
extern void fn_801F6228(void*, u16, u16);
extern const char lbl_8024FF00[];

int fn_8016DB38(void* state)
{
    void* object;
    int type;
    u16 second;
    u16 first;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object = fn_800F5C54(fn_8016A694(state, 1));
    type = (int)fn_8016A694(state, 2);
    if (object != 0) {
        fn_8016D9C0(type, &first, &second);
        fn_801F6228(object, first, second);
    }
    return 1;
}
