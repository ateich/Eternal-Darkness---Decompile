typedef unsigned char u8;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_80130214(void*, u8);
extern void fn_80130258(void*, unsigned int, unsigned int);
extern u8 fn_801303BC(void*);
extern void fn_80130434(void*, int);
extern const char lbl_8024FF00[];

int fn_8016F2AC(void* state)
{
    int mode;
    void* object;
    int index;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    object = fn_80201BC8(fn_80201814((int)fn_8016A694(state, 1)));
    mode = (int)fn_8016A694(state, 2);
    index = (int)fn_8016A694(state, 3);
    if (mode != 0) {
        if (index < 0) {
            fn_80130214(object, 0);
        } else {
            fn_80130258(object, 1 << index, 0);
        }
    } else {
        if (index < 0) {
            fn_80130434(object, 1);
            fn_80130214(object, 0xFF);
        } else {
            fn_80130258(object, 0, 1 << index);
            if (index == fn_801303BC(object)) {
                fn_80130434(object, 1);
            }
        }
    }
    return 0;
}
