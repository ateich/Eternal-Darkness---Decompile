typedef int s32;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

#pragma use_lmw_stmw on

extern float lbl_8064E06C;
extern float lbl_8064E070;
extern float lbl_8064E074;
extern float lbl_8064E078;
extern float lbl_8064E07C;

extern int fn_80200C10(void *);
extern int fn_80201B54();
extern void *fn_80201BC8();
extern void* fn_80201B94(void*);
extern u32 fn_80201CCC(void*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201E50(void*, u32);
extern int fn_801E8328();
extern void fn_80201D34(void *, s32);
extern void fn_80201D1C(void *, s32);
extern void fn_8011F114();
extern void fn_8011F0E8(void*, Vec3*);
extern void fn_8020104C(int, void *, void *, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))

s32 fn_8002C160(void* callback, s32 phase, void* event)
{
    Vec3 adjusted_start;
    Vec3 adjusted_first;
    Vec3 adjusted_second;
    Vec3 position_start;
    Vec3 position_first;
    Vec3 position_second;
    s32 event_id = fn_80200C10(event);
    s32 object_id = fn_80201B54(callback);
    void* flags_object;
    void* state;
    u32 flags;
    state = fn_80201BC8(callback);
    flags_object = fn_80201B94(callback);
    flags = fn_80201CCC(flags_object);

    if (phase == 0) {
        if (event_id == 1) {
            if (flags & 0x400000) {
                fn_80201D2C(callback, 0xC);
                fn_80201D14(callback, 1);
                fn_80201E50(flags_object, flags & ~0x400000);
            } else {
                fn_80201D2C(callback, 1);
                fn_80201D14(callback, 1);
            }
            return 1;
        }
        if (event_id == 0x39) {
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        if (event_id == 0x96) {
            fn_8011F114(&position_start, state);
            adjusted_start = position_start;
            adjusted_start.z -= lbl_8064E06C;
            fn_8011F0E8(state, &adjusted_start);
            return 1;
        }
        if (event_id == 0x13) {
            fn_80201D2C(callback, 0xE);
            fn_80201D14(callback, 1);
            return 1;
        }
        goto event_unhandled;
    }

    if (phase == 1) {
        if (event_id == 0x12) {
            fn_80201D2C(callback, 0xF);
            fn_80201D14(callback, 1);
            return 1;
        }
        goto event_unhandled;
    }

    if (phase == 0xC) {
        if (event_id == 0x12) {
            fn_80201D2C(callback, 0x26);
            fn_80201D14(callback, 1);
            return 1;
        }
        goto event_unhandled;
    }

    if (phase == 0xF) {
        if (event_id == 1) {
            fn_8020104C(0x14, object_id, object_id, 0, lbl_8064E070);
            return 1;
        }
        if (event_id == 0x14) {
            fn_80201D2C(callback, 0xC);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 3) {
            fn_8011F114(&position_first, state);
            adjusted_first = position_first;
            adjusted_first.z -= lbl_8064E074;
            fn_8011F0E8(state, &adjusted_first);
            return 1;
        }
        if (event_id == 2) {
            return 1;
        }
        goto event_unhandled;
    }

    if (phase == 0x26) {
        if (event_id == 1) {
            fn_8020104C(0x14, object_id, object_id, 0, lbl_8064E078);
            return 1;
        }
        if (event_id == 0x14) {
            fn_80201D2C(callback, 0xE);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 3) {
            fn_8011F114(&position_second, state);
            adjusted_second = position_second;
            adjusted_second.z -= lbl_8064E07C;
            fn_8011F0E8(state, &adjusted_second);
            return 1;
        }
        if (event_id == 2) {
            return 1;
        }
        goto event_unhandled;
    }

    if (phase == 0xE) {
        goto event_unhandled;
    }
    return 0;

event_unhandled:
    return 0;
}
