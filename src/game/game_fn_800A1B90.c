typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Object800A1B90 {
    unsigned char pad00[0xC];
    float radius;
} Object800A1B90;

extern Vec3 fn_80201E78(void*);
extern void fn_80211A6C(Vec3, Object800A1B90*, Vec3*);
extern int fn_800A4F44(Vec3*, float);
extern void* fn_80201B54(void*);
extern unsigned long long fn_8020123C(int, int, void*, Object800A1B90*);

int fn_800A1B90(Object800A1B90* object, int value, void* entity)
{
    int result = 0;
    Vec3 delta;

    if (entity != 0) {
        fn_80211A6C(fn_80201E78(entity), object, &delta);
        result = fn_800A4F44(&delta, object->radius) > 0;
        if (result) {
            fn_8020123C(0xA5, value, fn_80201B54(entity), object);
        }
    }
    return result;
}
