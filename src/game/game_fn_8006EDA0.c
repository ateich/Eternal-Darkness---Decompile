typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Config {
    unsigned char pad_00[0x18];
    short channels[4];
    unsigned char pad_20[0x0C];
    Vec3 position;
    float angle;
    unsigned char pad_3C[0xB8];
} Config;

typedef struct Owner {
    unsigned char pad_00[0xC4];
    Config *config;
} Owner;

typedef struct SourceResult {
    unsigned char pad_00[0xC4];
    Config *config;
} SourceResult;

extern SourceResult *fn_8006D444(void *object);
extern void *fn_80201BC8(void *object);
extern void *memset(void *dest, int value, unsigned int size);
extern void fn_801FABA4(void *object, int value);
extern float fn_8012B750(void *object);
extern void fn_8011F114(Vec3 *out, void *object);
extern void fn_80038308(Owner *owner, int channel, short *value);
extern unsigned char lbl_80312948[];
extern void *lbl_8064D18C;
extern int lbl_8064C8C0;

int fn_8006EDA0(Owner *owner, void *source)
{
    Config *config;
    void *object;
    Vec3 position;

    config = (Config *)((unsigned char *)fn_8006D444(source)->config + 0x48);
    object = fn_80201BC8(owner);
    memset(config, 0, 0xF4);
    fn_801FABA4(lbl_80312948, 0);
    lbl_8064C8C0 = 1;
    *(void **)config = lbl_8064D18C;
    config->angle = fn_8012B750(object);
    fn_8011F114(&position, object);
    config->position = position;
    fn_80038308(owner, 0, &config->channels[0]);
    fn_80038308(owner, 2, &config->channels[1]);
    fn_80038308(owner, 3, &config->channels[2]);
    fn_80038308(owner, 1, &config->channels[3]);
    return 1;
}
