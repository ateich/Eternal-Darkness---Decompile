typedef signed int s32;
typedef unsigned char u8;
typedef float f32;

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct ObjectWork {
    u8 unk0[0x1B4];
    s32 effect;
} ObjectWork;

typedef struct ObjectData {
    u8 unk0[0x44];
    ObjectWork *work;
} ObjectData;

extern void fn_8011F114(Vec3 *, void *);
extern void fn_80128B8C(void *, Vec3 *);
extern s32 fn_80128EAC(void *);
extern s32 fn_80128F40(void *);
extern Vec3 *fn_80137FB8(s32);
extern ObjectData *fn_80201B8C(void);
extern void fn_80201BD0(void *);
extern void fn_80211A6C(const Vec3 *, const Vec3 *, Vec3 *);
extern void fn_80211A90(const Vec3 *, Vec3 *, f32);
extern void fn_80211AAC(const Vec3 *, Vec3 *);
extern f32 fn_80211B08(const Vec3 *);
extern f32 lbl_8064E908;

s32 fn_800783F0(void *object)
{
    Vec3 difference;
    Vec3 position;
    s32 value;
    f32 distance;

    if (fn_80128EAC(object) == 0x4C) {
        fn_8011F114(&position, object);
        value = fn_80128F40(object);
        fn_80201BD0(object);
        fn_80211A6C(fn_80137FB8(fn_80201B8C()->work->effect),
                     &position, &difference);
        distance = fn_80211B08(&difference) - lbl_8064E908;
        fn_80211AAC(&difference, &difference);
        fn_80211A90(&difference, &difference,
                    distance / (f32)((0x89 - (value >> 17)) * 2));
        fn_80128B8C(object, &difference);
    }
    return 1;
}
