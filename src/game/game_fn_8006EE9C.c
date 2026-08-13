typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Config {
    unsigned char pad_00[0x74];
    Vec3 value;
} Config;

typedef struct Owner {
    unsigned char pad_00[0x38];
    void *resource;
    unsigned char pad_3C[0x88];
    Config *config;
} Owner;

extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_801FAD4C(void *object);
extern int fn_80158D38(Vec3 *value, int type, int size, Vec3 *out);
extern void fn_8006E754(Owner *owner, int enabled);
extern void fn_8006F544(Owner *owner, int enabled);
extern unsigned char lbl_80312948[];
extern int lbl_8064C8C0;

void fn_8006EE9C(Owner *owner)
{
    Config *config;
    Vec3 value;

    config = owner->config;
    fn_80201BC8(fn_80201814(owner->resource));
    if (lbl_8064C8C0 != 0) {
        fn_801FAD4C(lbl_80312948);
    }
    lbl_8064C8C0 = 0;
    if (fn_80158D38(&config->value, 2, 0x10, &value)) {
        config->value = value;
    }
    fn_8006E754(owner, 0);
    fn_8006F544(owner, 0);
}
