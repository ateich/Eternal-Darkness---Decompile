extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_80120AD0(void*, int, float, float, int, int);
extern const char lbl_8024FF00[];
extern float lbl_806506CC;

int fn_8016FD3C(void* state)
{
    int object_id;
    float value;
    int argument;
    int flags;
    void* object;

    if (fn_8016A598(state) != 4) {
        fn_80163BB4(state, lbl_8024FF00, 4, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (float)fn_8016A694(state, 2);
    argument = (int)fn_8016A694(state, 3);
    flags = (int)fn_8016A694(state, 4);
    object = fn_80201814(object_id);
    if (object != 0) {
        object = fn_80201BC8(object);
        if ((unsigned short)flags != 0) {
            flags = (flags | 2) & 0xFFFF;
        }
        fn_80120AD0(object, 0, lbl_806506CC, value, argument, flags);
    }
    return 0;
}
