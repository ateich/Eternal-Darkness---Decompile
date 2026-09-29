typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SixBytes {
    u32 word;
    u16 half;
} SixBytes;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef float Matrix34[3][4];

typedef struct Channel {
    u8 active;
    u8 kind;
    u8 pad2[2];
    u8 value;
    s8 step;
    u8 pad6;
    u8 limit;
    u16 generation;
    u8 padA[0x21];
    u8 level;
    u8 pad2C[0xC];
} Channel;

typedef struct VoiceState {
    u8 pad0;
    s8 pan;
    u8 pad2[3];
    u8 flags;
    u8 pad6[2];
    u16 id;
    u8 padA[0x36];
    u16 status;
    u8 pad42[0x12];
    Vec3 target;
    Vec3 angle;
    Vec3 limit;
} VoiceState;

typedef struct Voice {
    u8 pad0;
    u8 count;
    u8 value;
    u8 pad3;
    u8 step;
    u8 pad5[5];
    u16 generation;
    u16 duration;
    u8 padE[2];
    s16 position[3];
    u8 pad16[0xC];
    u16 timer;
    u8 pad24[0x28];
    Channel* channels;
    u8 pad50[0x3C];
    VoiceState state;
} Voice;


typedef struct Buffers {
    u8* vertices;
    u8* colors;
    u8* indices;
} Buffers;

typedef struct Quaternion {
    float x;
    float y;
    float z;
    float w;
} Quaternion;

extern u8 lbl_80607120[];
extern void* lbl_8064D738;
extern u32 lbl_80651D50;
extern u16 lbl_80651D54;
extern Vec3 lbl_8023B068;
extern const float lbl_80650A20;
extern const float lbl_80650A24;
extern const double lbl_80650A28;

extern void fn_8018D788(void*, void*, Buffers*, u16);
extern void fn_801869F8(void*, int, u16);
extern void fn_8018E26C(void*, void*);
extern void fn_8018680C(void*, void*, Vec3*, int, SixBytes*, u8);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern void fn_80210FB0(Matrix34);
extern void fn_80211A48(Vec3*, Vec3*, Vec3*);
extern void fn_80211268(Matrix34, int, float);
extern void fn_80210FDC(Matrix34, Matrix34, Matrix34);
extern void fn_80211B64(Vec3*, Vec3*, Vec3*);
extern float fn_80211B08(Vec3*);
extern void fn_80211AAC(Vec3*, Vec3*);
extern float fn_80211B44(Vec3*, Vec3*);
extern double fn_80102340(float, float);
extern void fn_8017A244(Vec3*, Quaternion*, float);
extern void fn_802114E0(Matrix34, Quaternion*);
extern void fn_80211484(Matrix34, float, float, float);
extern void fn_80211710(Matrix34, Vec3*, Vec3*);

int fn_801861C4(Voice* self)
{
    SixBytes setup;
    Buffers buffers;
    Vec3 direction;
    Vec3 origin;
    Quaternion rotation;
    Vec3 transformed;
    Matrix34 transform;
    Matrix34 translation;
    Matrix34 x_rotation;
    Matrix34 y_rotation;
    Matrix34 z_rotation;
    Matrix34 combined;
    Matrix34 result;
    float length;
    float dot;
    int changed = 0;
    Voice* self_local = self;
    u8 count;
    int generation;
    int index;
    int slot;
    VoiceState* state;
    Channel* entry;
    int vertex_index;
    int vertex_count;
    s16* vertex;

    state = &self_local->state;
    setup.word = lbl_80651D50;
    setup.half = lbl_80651D54;
    generation = self_local->generation;
    entry = self_local->channels;
    count = self_local->count;
    self_local->generation = generation + 1;

    fn_8018D788(lbl_8064D738, self_local, &buffers,
                *(u16*)(lbl_80607120 + 2));
    fn_801869F8(state, 0, state->id);

    for (index = 0, slot = 0; index < count; slot++, index++) {
        if (entry->active != 0) {
            fn_8018E26C(entry, &entry->level);
            if (changed == 0 && (state->flags & 4) != 0) {
                if (state->pan > 2) {
                    state->pan--;
                } else if (state->pan < -2) {
                    state->pan++;
                }
                changed = 1;
            }
        }
        fn_8018680C(state, entry,
                    (Vec3*)(buffers.vertices + slot * sizeof(Vec3)),
                    index, &setup, count);
        if ((int)generation == (int)entry->generation &&
            (state->flags & 1) == 0) {
            fn_8018E230(entry, &entry->level, 1, self_local->value,
                        self_local->step, 0);
        }
        entry++;
    }

    origin = lbl_8023B068;
    vertex = (s16*)buffers.vertices;
    vertex_count = (self_local->count & 0x7F) << 1;
    fn_80210FB0(transform);
    fn_80211A48(&state->angle, &state->limit,
                &state->angle);
    {
        float angle = state->angle.x;
        if (angle > lbl_80650A20)
            angle = state->limit.x;
        state->angle.x = angle;
    }
    {
        float angle = state->angle.y;
        if (angle > lbl_80650A20)
            angle = state->limit.y;
        state->angle.y = angle;
    }
    {
        float angle = state->angle.z;
        if (angle > lbl_80650A20)
            angle = state->limit.z;
        state->angle.z = angle;
    }

    fn_80211268(x_rotation, 0x78,
                lbl_80650A24 * state->angle.x);
    fn_80211268(y_rotation, 0x79,
                lbl_80650A24 * state->angle.y);
    fn_80211268(z_rotation, 0x7A,
                lbl_80650A24 * state->angle.z);
    fn_80210FDC(z_rotation, y_rotation, combined);
    fn_80210FDC(combined, x_rotation, result);

    fn_80211B64(&origin, &state->target, &direction);
    length = fn_80211B08(&direction);
    if (length > lbl_80650A28) {
        fn_80211AAC(&direction, &direction);
        dot = fn_80211B44(&origin, &state->target);
        fn_8017A244(&direction, &rotation,
                    (float)fn_80102340(length, dot));
        fn_802114E0(transform, &rotation);
    }
    fn_80210FDC(transform, result, transform);
    fn_80211484(translation, (float)self_local->position[0],
                 (float)self_local->position[1],
                 (float)self_local->position[2]);
    fn_80210FDC(translation, transform, transform);

    vertex_index = 0;
    while (vertex_index < vertex_count) {
        transformed.x = vertex[0];
        transformed.y = vertex[1];
        transformed.z = vertex[2];
        fn_80211710(transform, &transformed, &transformed);
        vertex[0] = transformed.x;
        vertex[1] = transformed.y;
        vertex[2] = transformed.z;
        vertex += 3;
        vertex_index++;
    }

    if ((state->status & 2) != 0 ||
        ((state->flags & 1) == 0 &&
         (int)generation >= (int)self_local->duration)) {
        self_local->timer = 8;
    }
    return 0;
}
