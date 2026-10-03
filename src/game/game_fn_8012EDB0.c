typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

typedef f32 Matrix[3][4];
typedef f32 Vec3Array[3];

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct Matrix34 {
    f32 m[3][4];
} Matrix34;

typedef union MatrixStorage {
    Matrix array;
    Matrix34 matrix;
} MatrixStorage;

typedef struct TransformOutput {
    u8 pad[8];
    Vec3Array first;
    Vec3Array second;
    u8 pad2[4];
    u8 enabled;
} TransformOutput;

typedef struct TransformLocalView {
    s32 index;
    s32 marker;
    Vec3 first;
    Vec3 second;
    f32 trailing;
    u8 enabled;
} TransformLocalView;

typedef union TransformStorage {
    TransformOutput output;
    TransformLocalView local;
} TransformStorage;

typedef struct Resource {
    u8 pad[0xE];
    u16 id;
} Resource;

typedef struct Entry {
    u8 pad[4];
    Resource* resource;
} Entry;

typedef struct Object {
    u8 pad[0x240];
    Entry** entries;
} Object;

typedef struct ObjectRuntimeLayout {
    u8 pad[0x160];
    u8* runtime;
} ObjectRuntimeLayout;

extern f32 lbl_806501D8;
extern f32 lbl_806501DC;
extern const double lbl_80650208;

extern void fn_80125ECC(void*);
extern int fn_8012FDA0(Object*, int);
extern void fn_8011F3B4(void*, Matrix, u16, int);
extern void fn_8011F304(TransformOutput*, Matrix, int);
extern void fn_80211AAC(const Vec3*, Vec3*);
extern void fn_80211B64(const Vec3*, const Vec3*, Vec3*);
extern f32 fn_80211B08(const Vec3*);
extern void fn_802110A8(void*, void*);
extern void fn_8017AD00(const Matrix34*, const Vec3*, Vec3*);
extern void fn_8017A244(const Vec3*, Vec4*, f32);
extern void fn_8012CEA4(u8*, int, Vec4*);
extern f32 fn_8017A5A8(const Vec4*, const Vec4*, f32);
extern void fn_8012CF08(u8*, int, Vec4, Vec4, int, int, f32);
extern void fn_8012F58C(void*, unsigned int, unsigned int, u16, u16, u16);

int fn_8012EDB0(s32 context, s32 index, Vec3* position, f32 angle,
                f32 limit)
{
    Object* object = (Object*)context;
    ObjectRuntimeLayout* runtime_layout = (ObjectRuntimeLayout*)object;
    MatrixStorage matrix;
    MatrixStorage inverse;
    TransformStorage transform;
    Vec3 cross;
    Vec3 axis;
    Vec4 desired;
    Vec4 current;
    Entry* entry;
    Resource* resource;
    int transform_id;
    f32 scale;

    fn_80125ECC(object);
    entry = object->entries[index];
    if (entry != 0) {
        resource = entry->resource;
        *(void**)(runtime_layout->runtime + resource->id * 0x4C + 0x48) = 0;

        transform_id = fn_8012FDA0(object, index);
        transform.local.index = index;
        transform.local.marker = -1;
        transform.local.first.x = lbl_806501D8;
        transform.local.first.y = lbl_806501D8;
        transform.local.first.z = lbl_806501D8;
        transform.local.second.x = lbl_806501DC;
        transform.local.second.y = lbl_806501D8;
        transform.local.second.z = lbl_806501D8;
        transform.local.trailing = lbl_806501DC;

        fn_8011F3B4(object, matrix.array, (u16)transform_id, 9);
        fn_8011F304(&transform.output, matrix.array, 9);

        fn_80211AAC(position, position);
        fn_80211B64(&transform.local.second, position, &cross);
        if (fn_80211B08(&cross) > lbl_80650208) {
            fn_802110A8(&matrix.matrix, &inverse.matrix);
            fn_8017AD00(&inverse.matrix, &cross, &axis);
            fn_8017A244(&axis, &desired, angle);
            fn_8012CEA4((u8*)object, index, &current);
            scale = fn_8017A5A8(&current, &desired, limit);
            fn_8012CF08((u8*)object, index, current, desired, 0, 0, scale);
            fn_8012F58C(object, index, 3, 0, 0, 0x84);
        }
    }
    return 0;
}
