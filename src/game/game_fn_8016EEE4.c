extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern int fn_8012A1BC(void*, int);
extern void fn_80128A84(void*, unsigned short, unsigned int);
extern const char lbl_8024FF00[];

int fn_8016EEE4(void* state)
{
    void* callback;
    void* object;
    int object_id;
    int value;
    int result;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    callback = fn_8016A784(state, 2);
    value = (int)fn_8016A694(state, 3);
    object = fn_80201814(object_id);
    if (object != 0) {
        object = fn_80201BC8(object);
        result = fn_8012A1BC(object, value);
        fn_80128A84(callback, 0, result);
    }
    return 0;
}
