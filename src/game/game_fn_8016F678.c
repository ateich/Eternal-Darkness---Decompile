extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_8011FA8C(void*, int, int);
extern const char lbl_8024FF00[];
extern const char lbl_8025005C[];

int fn_8016F678(void* state)
{
    int object_id;
    void* object;
    void* runtime;
    int clear_flags = 0;
    int set_flags = 0;
    int enabled;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    object = fn_80201814(object_id);
    if (object != 0) {
        runtime = fn_80201BC8(object);
        enabled = (int)fn_8016A694(state, 2);
        if (enabled != 0) {
            set_flags = 4;
        }
        if (enabled == 0) {
            clear_flags = 4;
        }
        fn_8011FA8C(runtime, clear_flags, set_flags);
    } else {
        fn_80163BB4(state, lbl_8025005C, object_id);
    }
    return 0;
}
