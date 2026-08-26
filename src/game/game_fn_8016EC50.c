extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54(double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void* fn_801294DC(void*, int, int, int);
extern void fn_8016A970(void*, void*, int);
extern const char lbl_8024FF00[];

int fn_8016EC50(void* state)
{
    int value;
    int converted;
    int object_id;
    int mode;
    void* object;
    void* result;

    if (fn_8016A598(state) != 4) {
        fn_80163BB4(state, lbl_8024FF00, 4, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    converted = fn_800F5C54(fn_8016A694(state, 3));
    mode = (int)fn_8016A694(state, 4);
    object = fn_80201814(object_id);
    object = object != 0 ? fn_80201BC8(object) : 0;
    result = object != 0 ? fn_801294DC(object, value, converted, mode) : 0;
    fn_8016A970(state, result, 0);
    return 1;
}
