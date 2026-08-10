typedef int s32;
typedef unsigned int u32;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

#pragma use_lmw_stmw on

extern const Vec3 lbl_80238CD0[3];
extern float lbl_8064E040;
extern float lbl_8064E044;

extern s32 fn_80200C10(void*);
extern int fn_80201B54();
extern void* fn_80201BC8();
extern void fn_8020104C(s32, s32, s32, s32, float);
extern void fn_8011FA8C(void*, int, int);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern void fn_801E8328(s32, void*);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern void fn_800C8394(void*, s32);
extern void fn_8012CBE8(void*, s32, Vec3*, Vec3*, Vec3*, s32);

s32 fn_8002BA80(void* callback, s32 phase, void* event)
{
    const Vec3* vectors = lbl_80238CD0;
    s32 event_id = fn_80200C10(event);
    void* state;
    s32 object_id = fn_80201B54(callback);
    state = fn_80201BC8(callback);

    if (phase == 0) {
        if (event_id == 1) {
            fn_8020104C(0x39, object_id, object_id, 0, lbl_8064E040);
            fn_8020104C(0x11, object_id, object_id, 0, lbl_8064E044);
            fn_8011FA8C(state, 0xC0, 0x1000002);
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x39) {
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        if (event_id == 0x3D) {
            fn_801E8328(2, callback);
            return 1;
        }
        if (event_id == 0x11) {
            fn_800C8394(state, -10);
            return 1;
        }
        if (event_id == 2) {
            return 1;
        }
        goto event_unhandled;
    }

    if (phase == 1) {
        if (event_id == 1) {
            Vec3 first;
            Vec3 second;
            Vec3 third;

            fn_8011FA8C(state, 0, 0x800);
            third = vectors[2];
            second = vectors[1];
            first = vectors[0];
            fn_8012CBE8(state, 0xF, &first, &second, &third, 1);
            return 1;
        }
        if (event_id == 3) {
            return 1;
        }
        if (event_id == 2) {
            return 1;
        }
        goto event_unhandled;
    }

    return 0;

event_unhandled:
    return 0;
}
