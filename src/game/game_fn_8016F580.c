extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_8012C478(void*, int, int);
extern const char lbl_8024FF00[];
extern const char lbl_8025005C[];

int fn_8016F580(void* state)
{
    int object_id;
    void* object;
    void* runtime;
    int index;
    int enabled;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    object = fn_80201814(object_id);
    if (object != 0) {
        runtime = fn_80201BC8(object);
        index = (int)fn_8016A694(state, 2);
        enabled = (int)fn_8016A694(state, 3);
        fn_8012C478(runtime, index, enabled);
    } else {
        fn_80163BB4(state, lbl_8025005C, object_id);
    }
    return 0;
}
