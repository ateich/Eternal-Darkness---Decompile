typedef signed int s32;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void *fn_80201BC8();
extern s32 fn_8011F130();
extern u32 fn_8011FAEC(void *object);
extern void fn_8011FADC(void *object, u32 flags);
extern void fn_8006AFA0(Vec3 *out, s32 source);
extern void fn_8006B0A0(Vec3 *value);
extern void fn_801E79A0(void *manager, s32 kind);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_801593FC(s32 id);
extern void fn_801593B4(s32 id);

extern void *lbl_8064C4E0;

void fn_8006A9D0(s32 object, s32 unused1, s32 unused2, s32 *result)
{
    s32 source;
    void *actor;
    u32 flags;
    Vec3 position;

    actor = fn_80201BC8();
    source = fn_8011F130();
    flags = fn_8011FAEC(actor);
    fn_8006AFA0(&position, source);
    fn_8006B0A0(&position);
    fn_801E79A0(lbl_8064C4E0, 0x54);
    fn_80201D2C((void *)object, 8);
    fn_80201D14((void *)object, 1);
    if (result != 0) {
        *result = 0x13;
    }
    fn_8011FADC(actor, flags & ~0xC0);
    fn_801593FC(0xD6);
    fn_801593B4(0x148);
    fn_801593B4(0xB6);
}
