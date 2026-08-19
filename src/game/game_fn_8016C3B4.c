typedef unsigned char u8;

extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern int fn_801B0B30(int);
extern void fn_801B05B0(int, u8);
extern const char lbl_8024FF00[];
extern const char lbl_8024FF30[];

int fn_8016C3B4(void* state)
{
    int object;
    int value;
    u8 byte_value;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    byte_value = (value > 0 ? value : 0) > 255
                     ? 255
                     : (value > 0 ? value : 0);
    if (value != byte_value) {
        fn_80163BB4(state, lbl_8024FF30, value);
    } else {
        object = fn_801B0B30(object);
        if (object != -1) {
            fn_801B05B0(object, byte_value);
        }
    }
    return 0;
}
