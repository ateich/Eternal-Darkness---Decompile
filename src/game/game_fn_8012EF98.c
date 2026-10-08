typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct QueryResult {
    u8 pad_0[8];
    Vec3 position;
    Vec3 direction;
    u8 pad_20[8];
} QueryResult;

typedef struct EntryRecord {
    u8 pad_0[0xE];
    u16 transform_index;
} EntryRecord;

typedef struct Entry {
    u8 pad_0[4];
    EntryRecord* record;
} Entry;

/* Internal view only; callers continue to pass their established object type. */
typedef struct ObjectLayout {
    u8 pad_0[0x240];
    Entry** entries;
    u8 pad_244[0x10];
    u32 flags;
} ObjectLayout;

typedef float MatrixArray[3][4];
typedef struct Matrix34 {
    float m[3][4];
} Matrix34;

typedef union MatrixStorage {
    MatrixArray array;
    Matrix34 matrix;
} MatrixStorage;

typedef struct Sphere {
    Vec3 center;
    float radius;
} Sphere;

extern float lbl_805AADC8[][3];
extern int lbl_8064CF30;
extern int lbl_8064CF34;

extern void fn_80125ECC(void*);
extern void fn_80127FD8(void*, int, MatrixArray);
extern void fn_80211A6C(const Vec3*, const Vec3*, Vec3*);
extern float fn_80211B08(const Vec3*);
extern void fn_80211AAC(const Vec3*, Vec3*);
extern int fn_8013DE44(const Vec3*, const Vec3*, const Vec3*, float,
                       float*, u8);
extern void fn_80211A90(const Vec3*, Vec3*, float);
extern void fn_80211A48(const Vec3*, const Vec3*, Vec3*);
extern void fn_80211B64(const Vec3*, const Vec3*, Vec3*);
extern float fn_80211B44(const Vec3*, const Vec3*);
extern float fn_800490E8(float, float);
extern void fn_802110A8(void*, void*);
extern void fn_8017AD00(const Matrix34*, const Vec3*, Vec3*);
extern void fn_8017A244(const Vec3*, Vec4*, float);

int fn_8012EF98(void* object_ptr, int index, QueryResult* first,
                QueryResult* second, const Vec3* target, Vec4* output,
                float limit)
{
    ObjectLayout* object = (ObjectLayout*)object_ptr;
    MatrixStorage matrix;
    MatrixStorage inverse;
    Vec3 point[2]; /* only [0] is used; retail reserves the full 24 bytes */
    Vec3 target_delta;
    Vec3 cross;
    Vec3 local_axis;
    Vec3 axis;
    Vec3 local_point;
    Vec3 direction;
    Sphere sphere;
    Vec3 debug_direction;
    float intersection;
    Vec3* debug_vectors = (Vec3*)lbl_805AADC8;
    float cross_length;
    float axis_dot;
    float angle;
    float axis_angle;
    int result = 0;
    Entry* entry;

    fn_80125ECC(object_ptr);
    entry = object->entries[index];
    if (entry != 0) {
        fn_80127FD8(object_ptr, entry->record->transform_index, matrix.array);
        sphere.center.x = matrix.array[0][3];
        sphere.center.y = matrix.array[1][3];
        sphere.center.z = matrix.array[2][3];

        fn_80211A6C(target, &sphere.center, &target_delta);
        sphere.radius = fn_80211B08(&target_delta);
        fn_80211AAC(&target_delta, &target_delta);
        fn_80211AAC(&first->direction, &direction);

        if (fn_8013DE44(&first->position, &direction, &sphere.center, sphere.radius,
                        &intersection, 0)) {
            result = 1;
            fn_80211A90(&direction, &direction, intersection);
            fn_80211A48(&first->position, &direction, &point[0]);
            fn_80211A6C(&point[0],&sphere.center, &local_point);
            fn_80211B64(&local_point, &target_delta, &cross);
            cross_length = fn_80211B08(&cross);
            fn_80211AAC(&cross, &cross);
            axis_dot = fn_80211B44(&local_point, &target_delta);
            angle = fn_800490E8(cross_length, axis_dot);

            if ((object->flags & 0x80000000U) != 0) {
                fn_80211B64(&first->direction, &target_delta, &axis);
                axis_dot = fn_80211B44(&first->direction, &target_delta);
            } else {
                fn_80211B64(&second->direction, &target_delta, &axis);
                axis_dot = fn_80211B44(&second->direction, &target_delta);
            }
            axis_angle = fn_800490E8(fn_80211B08(&axis), axis_dot);
            if (axis_angle > limit) {
                angle = limit + (angle - axis_angle);
            }

            fn_802110A8(&matrix.matrix, &inverse.matrix);
            fn_8017AD00(&inverse.matrix, &cross, &local_axis);
            fn_8017A244(&local_axis, output, angle);

            if (lbl_8064CF30 != 0 && index == lbl_8064CF34) {
                debug_vectors[0] = *target;
                debug_vectors[3] = first->position;
                debug_direction = first->direction;
                fn_80211AAC(&debug_direction, &debug_direction);
                fn_80211A90(&debug_direction, &debug_direction, sphere.radius);
                fn_80211A48(&debug_vectors[3], &debug_direction,
                             &debug_vectors[4]);

                debug_vectors[5] = second->position;
                debug_direction = second->direction;
                fn_80211AAC(&debug_direction, &debug_direction);
                fn_80211A90(&debug_direction, &debug_direction, sphere.radius);
                fn_80211A48(&debug_vectors[5], &debug_direction,
                             &debug_vectors[6]);

                debug_vectors[7] = sphere.center;
                fn_80211A48(&debug_vectors[7], &local_point,
                             &debug_vectors[8]);
            }
        }
    }
    return result;
}
