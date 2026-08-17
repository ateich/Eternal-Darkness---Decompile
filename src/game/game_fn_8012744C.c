typedef unsigned char u8;
typedef signed short s16;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct PackedVec3 {
    s16 x;
    s16 y;
    s16 z;
} PackedVec3;

typedef struct Owner {
    u8 pad0[0x154];
    Vec3f* vectors;
    void* packed_vectors;
} Owner;

typedef struct RangeState {
    u8 pad0[0x10];
    int kind;
    PackedVec3 vector;
} RangeState;

extern void fn_801285D8(int*, int);
extern void fn_801252D8(int);
extern void fn_80128108(void*, PackedVec3*);

void fn_8012744C(Owner* owner, int index, RangeState* state, int flags)
{
    Vec3f* source;

    if ((flags & 2) != 0) {
        source = &owner->vectors[index];
        fn_801285D8(&state->kind, 1);
        fn_801252D8(4);
        state->vector.x = source->x;
        state->vector.y = source->y;
        state->vector.z = source->z;
    } else if ((flags & 1) != 0) {
        fn_801285D8(&state->kind, 2);
        fn_80128108((u8*)owner->packed_vectors + index * 0x10,
                    &state->vector);
    }
}
