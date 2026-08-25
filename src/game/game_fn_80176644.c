extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void fn_802020B4(void*, int);
extern const char lbl_8024FF00[];

int fn_80176644(void* state)
{
    int object_id;
    int value;
    void* object;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    object = fn_80201814(object_id);
    if (object != 0) {
        fn_802020B4(object, value);
    }
    return 0;
}
