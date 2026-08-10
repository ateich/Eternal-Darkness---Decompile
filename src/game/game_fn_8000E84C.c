typedef unsigned short u16;
typedef signed short s16;
typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const Vec3 lbl_80237F20;
extern const float lbl_8064DCF0;
extern void* fn_80201814();
extern void fn_80201E78(Vec3*, void*);
extern s32 fn_80035628(void*);
extern void fn_80158D38(Vec3*, s32, s32, Vec3*);
extern s32 fn_801D1B10(s32, s32, s32, s32);
extern void* fn_801A717C(s32);
extern void fn_801A74A0(void*, s32);
extern void fn_801A74A8(void*, s32);
extern void fn_801A7518(void*, s32);
extern void fn_801A7538(void*, u16);
extern void fn_801A7588(void*, s32);
extern void fn_801A764C(void*, Vec3*);
extern void fn_8020104C(s32, s32, s32, void*, float);

void fn_8000E84C(s32 object_id, s32 value)
{
    void* event;
    void* object;
    s32 event_value;
    Vec3 transformed;
    Vec3 position;

    event = fn_801A717C(object_id);
    if (event != 0) {
        position = lbl_80237F20;
        object = fn_80201814(object_id);
        fn_801A74A0(event, 0);
        fn_801A74A8(event, object_id);
        fn_801A7538(event, 1);
        event_value = fn_801D1B10(5, fn_80035628(object), value, 2);
        fn_801A7518(event, event_value);
        fn_801A7588(event, 2);
        fn_80201E78(&transformed, object);
        fn_80158D38(&transformed, 2, 4, &position);
        fn_801A764C(event, &position);
        fn_8020104C(0xED, 0, object_id, event, lbl_8064DCF0);
    }
}
