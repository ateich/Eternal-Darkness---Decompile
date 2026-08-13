typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern double lbl_8064E9D8;
extern float lbl_8064E9FC;
extern u8 lbl_802FC5BC[];

extern s32 fn_801A7498(void *);
extern void *fn_8004914C(void *);
extern void *fn_80201B9C(void *);
extern void *fn_80204844(void *, s32);
extern s32 fn_8011F6A4(void *, s32, s32, s32, void *, s32);
extern void *fn_8006D444(void *);
extern void fn_801AC9F4(s32, s32, Vec3 *, s32);
extern s32 fn_800FBFB0(void);
extern void fn_8014D478(s32, Vec3 *, Vec3 *, s32, s32, void *, s32);
extern s32 fn_801A9EF4(s32, s32);
extern void fn_80201814(void *);
extern void *fn_80201BC8(void);
extern float fn_8012B750(void *);
extern void fn_8011F114(Vec3 *, void *);
extern void fn_8020123C(s32, s32, s32, s32, s32);

/* NonMatching: honest reconstruction of the effect/event callback. */
s32 fn_8007D4D8(void *unused, void *handle)
{
    s32 owner_id;
    void *object;
    void *resource;
    u8 *state;
    u8 *slot;
    s32 result;
    Vec3 position;
    Vec3 velocity;
    Vec3 direction;
    void *target;

    (void)unused;
    if (handle != 0) {
        owner_id = fn_801A7498(handle);
        object = fn_8004914C(handle);
        if (object != 0) {
            resource = fn_80204844(fn_80201B9C(object), 0x20);
            result = fn_8011F6A4(object, 2, -1, -1, &direction, 1);
            state = fn_8006D444(resource);
            slot = *(u8 **)(state + 0xC4);
            if (result != -1) {
                fn_801AC9F4(0x176, 0x64, &position, 2);
                velocity.x = (float)(8 - (fn_800FBFB0() & 0xF));
                velocity.y = (float)(8 - (fn_800FBFB0() & 0xF));
                velocity.z = lbl_8064E9FC;
                fn_8014D478(0, &position, &velocity, 0x10, 4,
                            lbl_802FC5BC + 0x18, 3);
                fn_801AC9F4((u16)fn_801A9EF4(0x115, 0x117), 0x6E,
                            &position, 2);
            }
            fn_80201814(*(void **)(state + 0x38));
            target = fn_80201BC8();
            *(float *)(slot + 0x80) = fn_8012B750(target);
            fn_8011F114(&direction, target);
            *(Vec3 *)(slot + 0x74) = direction;
            fn_8020123C(8, 0, owner_id, 0, *(s32 *)&direction);
        }
    }
    return 1;
}
