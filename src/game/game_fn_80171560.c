extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_801296F8(void*, int);
extern void fn_8011FB5C(void*, int);
struct ErrorStrings {
    char argument_count;
    char pad_001[0x343];
    char object_not_found[0x1C];
    char component_not_found[1];
};
extern const struct ErrorStrings lbl_8024FF00;

int fn_80171560(void* state)
{
    const struct ErrorStrings* errors = &lbl_8024FF00;
    int object_id;
    int value;
    void* object;
    void* component;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, &errors->pad_001[-1], 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    object = fn_80201814(object_id);
    if (object == 0) {
        fn_80163BB4(state, errors->object_not_found, object_id);
        return 0;
    }

    component = fn_80201BC8(object);
    if (component == 0) {
        fn_80163BB4(state, errors->component_not_found, object_id, object);
        return 0;
    }

    fn_801296F8(component, value);
    fn_8011FB5C(component, value);
    return 0;
}
