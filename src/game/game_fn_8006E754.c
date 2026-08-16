typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Config {
    unsigned char pad_00[0x60];
    short channels[4];
    Vec3 direction;
    Vec3 position;
    float angle;
    unsigned char pad_84[0x18];
    int effect1;
    int effect2;
    int effect4;
} Config;

typedef struct Owner {
    unsigned char pad_00[0x38];
    void *resource;
    unsigned char pad_3c[0x88];
    Config *config;
} Owner;

extern void *fn_80201814();
extern void *fn_80201BC8();
extern int fn_8006BCE4(Owner *owner);
extern void fn_8011F104(void *object, float x, float y, float z);
extern void fn_8012B7A0(void *object, float angle);
extern void fn_801D13D8(void *resource, int value);
extern void fn_8011F114();
extern Vec3 *fn_8011F770(void *object);
extern short *fn_8006ED3C(Owner *owner, int type, short *result);
extern void fn_8012AC74(void *object, Vec3 *value, int count);
extern void fn_800C1B50(void *resource, int type, int value, float a, float b);
extern void fn_8012C478(void *object, int index, int value);
extern int fn_80201B54();
extern void *fn_80158598(void *object, int value);
extern void *fn_80201C24(void *object);
extern void fn_80157E34(void *object, int effect, int type, void *callback, int value);
extern void fn_800389E0(void *resource, int channel, int value, int zero);
extern const float lbl_8064E7E0;

static void start_effect(void *source, void *resource_object, Config *config,
                         int effect, int type)
{
    void *effect_object;
    void *target;
    void **vtable;

    if (effect == -1) {
        return;
    }
    effect_object = fn_80201814((void *)effect);
    if (effect_object == 0) {
        return;
    }
    target = fn_80158598((void *)fn_80201B54(resource_object), 0);
    vtable = (void **)fn_80201C24(effect_object);
    fn_80157E34(target, effect, type, *(void **)((unsigned char *)*vtable + 0x18), 0);
}

void fn_8006E754(Owner *owner, int enabled)
{
    Config *config;
    void *resource_object;
    void *object;
    int kind;
    Vec3 value;
    Vec3 *target;
    short count;

    config = owner->config;
    resource_object = fn_80201814(owner->resource);
    object = fn_80201BC8(resource_object);
    kind = fn_8006BCE4(owner);

    if (!enabled) {
        fn_8011F104(object, config->position.x, config->position.y, config->position.z);
        fn_8012B7A0(object, config->angle);
        fn_801D13D8(owner->resource, 0);
    } else if (kind == 0x23) {
        fn_8011F114(&value, object);
        target = fn_8011F770(object);
        fn_8006ED3C(owner, 0x23, &count);
        if (count > 0) {
            *target = config->direction;
            fn_8012AC74(object, &value, 3);
        }
    } else if (kind == 0x20 || kind == 0x21) {
        fn_8011F114(&value, object);
        fn_800C1B50(owner->resource, 0xF, 1, lbl_8064E7E0, lbl_8064E7E0);
        fn_8012AC74(object, &value, 3);
    }

    fn_8012C478(object, 0, 1);
    fn_8012C478(object, 1, 1);
    fn_8012C478(object, 2, 1);
    fn_8012C478(object, 3, 1);

    start_effect(object, resource_object, config, config->effect2, 2);
    start_effect(object, resource_object, config, config->effect1, 1);
    start_effect(object, resource_object, config, config->effect4, 4);

    fn_800389E0(resource_object, 0, config->channels[0], 0);
    fn_800389E0(resource_object, 2, config->channels[1], 0);
    fn_800389E0(resource_object, 3, config->channels[2], 0);
    fn_800389E0(resource_object, 1, config->channels[3], 0);
}
