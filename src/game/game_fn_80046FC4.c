typedef struct Target {
    char pad0[0x8];
    int dirty;
    char pad1[0xC];
    int object_id;
    int model_id;
} Target;

typedef struct Holder {
    char pad0[0x3C];
    Target *target;
} Holder;

extern void *fn_80201B9C(void);
extern void *fn_80204844(void *object, int type);
extern Holder *fn_80201B8C(void *object);
extern void *fn_80201814(int id);
extern void *fn_80201BC8(void *object);
extern void fn_801261F4(void *object);
extern void fn_8011FB54(void *object, void *value);
extern int fn_80201AE4(void);
extern void fn_801D13D8(int id, int notify);

void fn_80046FC4(int model_id, int notify)
{
    Target *target;
    void *model;
    void *object;

    object = fn_80204844(fn_80201B9C(), 0x22);
    if (object != 0) {
        target = fn_80201B8C(object)->target;
        if (target->object_id != 0 &&
            (object = fn_80201814(target->object_id)) != 0) {
            model = fn_80201BC8(object);
            fn_801261F4(model);
            if (model != 0) {
                if (target->model_id != model_id) {
                    target->dirty = 1;
                    target->model_id = model_id;
                }
                fn_8011FB54(model, (void *)model_id);
            }
        }
    }
    fn_801D13D8(fn_80201AE4(), notify);
}
