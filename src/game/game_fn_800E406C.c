typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct ResourceKey {
    u32 word;
    u16 half;
} ResourceKey;

typedef struct EffectDesc {
    u8 kind;
    u8 width;
    u8 alpha;
    u8 mode;
    u16 count;
    u16 height;
    u8 pad08[0x0C];
    u16 lifetime;
    u8 pad16[2];
    u8 color[4];
    u8 pad1C;
    u8 flags;
    u8 pad1E[2];
    u8 variant;
    u8 pad21;
    u8 enabled;
    u8 pad23[0x89];
} EffectDesc;

extern u32 lbl_8064F694;
extern u16 lbl_8064F698;
extern u32 lbl_8064F69C;
extern float lbl_8064F6A0;
extern float lbl_8064F6A4;
extern int lbl_8064D18C;

extern void *fn_80201BC8();
extern int fn_80201B54();
extern int fn_8011F6A4(void *, int, int, int, Vec3 *, int);
extern void fn_80154340(int, int, int, int, int, int, int, float);
extern void fn_801A19BC(EffectDesc *);
extern void fn_801AAE68(int, int, int, float, Vec3 *, int, int, int, u16, int);
extern void fn_801A1BD0(void);
extern void fn_80148008(Vec3 *, ResourceKey *, EffectDesc *, void *);
extern void fn_8019D560(EffectDesc *);
extern void fn_80152F90(Vec3 *, ResourceKey *, EffectDesc *, int);

void fn_800E406C(int id)
{
    u32 color;
    ResourceKey key;
    Vec3 placed;
    Vec3 position;
    Vec3 query_position;
    EffectDesc effect;
    void *resource;
    u8 alpha;

    resource = fn_80201BC8(id);
    if (fn_8011F6A4(resource, 9, 1, -1, &query_position, 1) == -1)
        return;

    key.word = lbl_8064F694;
    key.half = lbl_8064F698;
    color = lbl_8064F69C;
    fn_80154340(fn_80201B54(id), 9, 1, 10, 120, 1, 128,
                lbl_8064F6A0);

    fn_801A19BC(&effect);
    effect.count = 100;
    effect.lifetime = 12;
    fn_801AAE68(466, 125, 0, lbl_8064F6A4, &position, 2, 1, 0,
                (u16)lbl_8064D18C, 0);
    placed = position;
    fn_80148008(&placed, &key, &effect, fn_801A1BD0);
    fn_8019D560(&effect);

    alpha = ((u8 *)&color)[3];
    effect.kind = 16;
    effect.width = 16;
    effect.alpha = alpha;
    effect.mode = 0xFE;
    effect.count = 100;
    effect.height = 24;
    effect.lifetime = 12;
    effect.color[0] = ((u8 *)&color)[0];
    effect.color[1] = ((u8 *)&color)[1];
    effect.color[2] = ((u8 *)&color)[2];
    effect.color[3] = alpha;
    effect.flags = 64;
    effect.variant = 5;
    effect.enabled = 0;
    fn_80152F90(&position, &key, &effect, 200);
}
