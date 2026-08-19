typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

#pragma use_lmw_stmw on

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct RuntimeObject {
    u8 pad00[0x8C];
    u8 *effect_data;
} RuntimeObject;

typedef struct EffectData {
    u8 pad00[0xA0];
    Vec3 target;
} EffectData;

extern u32 lbl_80651950;
extern const u32 lbl_8064E5E4;
extern const u32 lbl_8064E5E8;
extern const float lbl_8064E5EC;
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void *fn_80201BC8();
extern int fn_80200C38();
extern void *fn_801A7498(void *);
extern void *fn_80201814();
extern void fn_8011F114();
extern void fn_801A7728(Vec3 *, void *);
extern void fn_8012B344();
extern void fn_8012C62C(void *, s32, u32 *, u32 *, u32 *, s32);
extern int fn_80201B44();
extern void fn_80145478(s32);
extern void *fn_801294DC(void *, int, int, int);
#define fn_801294DC(a, b, c, d) fn_801294DC((void *)(a), (b), (c), (d))
extern void fn_800359A0(void *, void *);
extern void fn_801D38BC(s32, u32 *, s16 *);
extern void fn_8014F65C(Vec3 *, s32, float, s16, s32, u32 *);
extern void fn_8014F5B8(Vec3 *, s32, float, s16, s32, u32 *);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_8005FF94(void *entry, void *object)
{
    RuntimeObject *runtime;
    EffectData *data;
    s32 entry_id;
    void *created;
    void *resource;
    void *entry_object;
    Vec3 position;
    Vec3 target;
    u32 output;
    s16 kind;
    u32 value0;
    u32 value1;
    u32 value2;
    u32 event0;
    u32 event1;

    runtime = fn_80201B8C(entry);
    data = (EffectData *)runtime->effect_data;
    entry_id = fn_80201B54(entry);
    entry_object = fn_80201BC8(entry);
    resource = (void *)fn_80200C38(object);
    created = fn_80201814(fn_801A7498(resource));

    fn_8011F114(&position, entry_object);
    fn_801A7728(&target, resource);
    data->target = target;
    fn_8012B344(entry_object);

    value2 = lbl_80651950;
    value1 = lbl_8064E5E8;
    value0 = lbl_8064E5E4;
    fn_8012C62C(entry_object, 0xF, &value0, &value1, &value2, 4);

    if (entry_id == fn_80201B44()) {
        fn_80145478(0x37);
    }
    fn_801294DC(entry_object, 0xB, 0x20, 8);
    fn_800359A0(entry, created);

    fn_801D38BC(2, &output, &kind);
    event0 = output;
    fn_8014F65C(&position, 100, lbl_8064E5EC, kind, 0, &event0);
    event1 = output;
    fn_8014F5B8(&data->target, 100, lbl_8064E5EC, kind, 0, &event1);

    fn_80201D2C(entry, 0x30);
    fn_80201D14(entry, 1);
}
