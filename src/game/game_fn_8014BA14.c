typedef signed short s16;
typedef unsigned int u32;
typedef struct Vec3 { float x, y, z; } Vec3;

extern u32 lbl_8064D5A8;
extern u32 lbl_8064D0AC;
extern const float lbl_806504AC;

extern unsigned char fn_8018F764(void*);
extern void fn_80198C8C(void*, int, int, int, int, int);
extern void* fn_8011FE4C(void*);
extern int fn_80201A84(int);
extern void *fn_80201814();
extern unsigned long long fn_8020123C();
extern int fn_80201B64(void*);
extern int fn_80201B44();
extern void* fn_801A717C(void);
extern void fn_801A74A0(void*, int);
extern void fn_801A74A8(void*, int);
extern void fn_801A7538(void*, int);
extern void fn_801A7518(void*, int);
extern void fn_801A7588(void*, int);
extern void fn_80201E78(Vec3*, void*);
extern u32 fn_80179004(Vec3*, Vec3*);
extern void fn_801A764C(void*, Vec3*);
extern void fn_801A7670(void*, int);
extern void fn_8020104C(int, int, int, void*, float);
extern int fn_801A98F4(int, int);

void fn_8014BA14(s16* first, s16* second, int id, void* owner)
{
    int special = 0;
    int effect = 0;
    int allowed = 1;
    int zone;
    void* room;
    void* spawn;
    Vec3 point;
    Vec3 a;
    Vec3 b;
    Vec3 middle;
    u32 da, db, dm;

    if (id == 0)
        return;
    if (id == -1 || id == -2) {
        special = 1;
    } else if (id == -3) {
        effect = 1;
        special = 1;
    } else if (id == -4) {
        effect = 2;
        special = 1;
    }

    if (owner != 0) {
        int type = fn_8018F764(owner);
        int kind = type == 9 ? 6 : 1;
        int strength = type == 9 ? 150 : 90;
        if (id == -1) {
            fn_80198C8C(owner, kind, 255, -3, strength, 0);
        } else if (id >= -4 && id <= -2) {
            fn_80198C8C(owner, kind, 255, -3, strength,
                        (effect + 1) * 17 - 5);
        } else {
            fn_80198C8C(owner, kind, 220, -2, strength, 0);
        }
    }
    if (special)
        return;

    zone = fn_80201A84(id);
    room = fn_80201814();
    if (id != 0 && fn_8011FE4C((void*)id) != (void*)id) {
        zone = fn_80201A84((int)fn_8011FE4C((void*)id));
        room = fn_80201814();
    }
    fn_8020123C(59, -1, zone, 4);
    if (room == 0 || fn_80201B64(room) == 8)
        return;
    if (zone == fn_80201B44()) {
        int elapsed = (int)(lbl_8064D5A8 - lbl_8064D0AC);
        if (elapsed > 120 || (elapsed < 0 && (int)(elapsed + 0x80000000U - 1) > 119))
            lbl_8064D0AC = lbl_8064D5A8;
        else
            allowed = 0;
    }
    if (!allowed || (spawn = fn_801A717C()) == 0)
        return;

    fn_801A74A0(spawn, 0);
    fn_801A74A8(spawn, zone);
    fn_801A7538(spawn, 1);
    fn_801A7518(spawn, 10);
    fn_801A7588(spawn, 2);
    fn_80201E78(&point, room);
    a.x = first[0]; a.y = first[1]; a.z = first[2];
    b.x = second[0]; b.y = second[1]; b.z = second[2];
    da = fn_80179004(&point, &a);
    db = fn_80179004(&point, &b);
    middle.x = first[0] + ((second[0] - first[0]) >> 1);
    middle.y = first[1] + ((second[1] - first[1]) >> 1);
    middle.z = first[2] + ((second[2] - first[2]) >> 1);
    dm = fn_80179004(&point, &middle);
    if (da < db)
        fn_801A764C(spawn, da < dm ? &a : &middle);
    else
        fn_801A764C(spawn, db < dm ? &b : &middle);
    fn_801A7670(spawn, 0);
    fn_8020104C(237, -1, zone, spawn, lbl_806504AC);
    fn_801A98F4(552, 100);
}
