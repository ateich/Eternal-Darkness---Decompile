extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void* fn_801295E8(void*, int, unsigned short, int);
extern void fn_8016A970(void*, void*, int);
extern const char lbl_8024FF00[];
extern const char lbl_80250028[];

int fn_8016EB1C(void* state)
{
    int value;
    unsigned short kind;
    int object_id;
    int mode;
    void* result;

    if (fn_8016A598(state) != 4) {
        fn_80163BB4(state, lbl_8024FF00, 4, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    kind = (unsigned short)(int)fn_8016A694(state, 3);
    mode = (int)fn_8016A694(state, 4);
    result = fn_801295E8(fn_80201BC8(fn_80201814(object_id)), value, kind, mode);
    fn_8016A970(state, result, 0);
    if (result == 0) {
        fn_80163BB4(state, lbl_80250028, 0);
    }
    return 1;
}
