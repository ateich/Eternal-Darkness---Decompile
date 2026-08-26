extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011FABC(void*, int, int);
extern const char lbl_8024FF00[];

int fn_8016FC68(void* state)
{
    int object_id;
    int clear_flags;
    int set_flags;
    void* object;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    clear_flags = (int)fn_8016A694(state, 2);
    set_flags = (int)fn_8016A694(state, 3);
    object = fn_80201814(object_id);
    if (object != 0) {
        fn_8011FABC(fn_80201BC8(object), clear_flags, set_flags);
    }
    return 0;
}
