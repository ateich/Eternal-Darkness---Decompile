typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Fallback {
    u8 pad0[0x1E];
    s16 count;
} Fallback;

typedef struct Transform {
    u8 pad0[0x94];
    Vec3 position;
} Transform;

typedef struct RuntimeData {
    unsigned char pad0[80];
    Fallback* fallback;
    unsigned char pad54[56];
    Transform* transform;
} RuntimeData;

extern void *fn_80201B8C();
extern void* fn_80201B94();
extern int fn_80201B54();
extern int fn_80201B44();
extern void *fn_80201814();
extern void fn_8011F114();
extern int fn_800CB098(int, int, int, void*, int, int);
extern int fn_80038308(void*, int, s16*);
extern int fn_80038464(void*, int, s16*);
extern int fn_8008D9F4(void*, void*, void*, int);
extern void fn_800073D8(void*);
extern void fn_80201DD8(void*, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern int fn_80036E50(void*);
extern float fn_8012B7D0(void*, Vec3*);
extern float fn_8012B750(void*);
extern void fn_8017A12C(float*, float, float);
extern void* fn_801A717C(void);
extern void fn_801A74A0(void*, int);
extern void fn_801A74A8(void*, int);
extern void fn_801A7470(void*, int);
extern unsigned long long fn_8020123C();
extern void fn_801A7228(void*);
extern void* lbl_8064D18C;
extern void* lbl_8064C4E4;
extern u32 lbl_8064D5A8;
extern const float lbl_8064EC08;
extern const float lbl_8064EC0C;
extern const float lbl_8064EC10;
extern const float lbl_8064EC14;

int fn_8008CEF0(void* object, void* position, void* context)
{
    RuntimeData* data;
    Fallback* fallback;
    Transform* transform;
    void* runtime;
    int target;
    void* mode;
    Vec3 unused_position, stored_position, world_position, query_position;
    s16 denominator, numerator;
    int low, high;
    int result = 0;
    int value;
    int pending = 1;
    float ratio;

    data = fn_80201B8C(object);
    fallback = data->fallback;
    transform = data->transform;
    runtime = fn_80201B94(object);
    target = fn_80201B54(object);
    value = fn_80201B44();
    mode = fn_80201814();
    fn_8011F114(&unused_position, position);
    low = fn_800CB098(2, 10, -1, lbl_8064D18C, 1, 0);
    high = fn_800CB098(2, 24, -1, lbl_8064D18C, 1, 0);
    fn_80038308(object, 0, &numerator);
    fn_80038464(object, 0, &denominator);
    ratio = (float)numerator / (float)denominator;

    if (fallback->count == 0) {
        if (ratio > lbl_8064EC08 && low != 0) {
            int first;
            first = fn_8008D9F4(object, position, context, 1);
            if (first == 0) {
                fn_800073D8(lbl_8064D18C);
                return 0;
            }
            fn_80201DD8(runtime, first);
            fn_80201D2C(object, 3);
            fn_80201D14(object, 1);
            result = 1;
            pending = 0;
        } else if (ratio < lbl_8064EC0C && (low != 0 || high != 0)) {
            int first, second;
            first = fn_8008D9F4(object, position, context, 1);
            second = fn_8008D9F4(object, position, context, 2);
            if (first == 0 && second == 0) {
                pending = 1;
            } else {
                fn_80201DD8(runtime, second != 0 ? second : first);
                fn_80201D2C(object, 3);
                fn_80201D14(object, 1);
                result = 1;
                pending = 0;
            }
        } else if ((low != 0 || high != 0) && fn_80036E50(mode) == 6) {
            int first, second;
            first = fn_8008D9F4(object, position, context, 1);
            second = fn_8008D9F4(object, position, context, 2);
            if (first != 0 || second != 0) {
                fn_80201DD8(runtime, second != 0 ? second : first);
                fn_80201D2C(object, 3);
                fn_80201D14(object, 1);
                result = 1;
                pending = 0;
            }
        }
    }

    if (pending != 0) {
        if (fn_80036E50(mode) != 6) {
            fn_80201DD8(runtime, value);
            fn_80201D2C(object, 3);
            fn_80201D14(object, 1);
            result = 1;
        } else if ((u8)lbl_8064D5A8 == 0) {
            float facing, current, angle, magnitude;

            fn_8011F114(&world_position, lbl_8064C4E4);
            query_position = stored_position = world_position;
            facing = fn_8012B7D0(position, &query_position);
            current = fn_8012B750(position);
            fn_8017A12C(&angle, current, facing);
            magnitude = angle;
            if (magnitude < lbl_8064EC10) magnitude = -magnitude;
            if (magnitude > lbl_8064EC14) {
                transform->position = stored_position;
                fn_80201D2C(object, 0x15);
                fn_80201D14(object, 1);
            } else if ((lbl_8064D5A8 & 0x1FF) == 0) {
                void* event = fn_801A717C();
                fn_801A74A0(event, target);
                fn_801A74A8(event, target);
                fn_801A7470(event, 0x10);
                fn_8020123C(0x35, target, target, event);
                fn_801A7228(event);
            }
        }
    }
    return result;
}
