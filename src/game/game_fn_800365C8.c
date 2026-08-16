typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct State {
    u8 pad00[0x2C];
    Vec3 source_position;
    Vec3 target_position;
    u8 pad44[0x10];
    s32 path_value;
    u8 pad58[0x1C];
    s32 target_id;
    s32 source_id;
    u8 pad7C[0x12];
    s16 timer;
} State;

typedef struct ObjectInfo {
    State* state;
    u8 pad04[0x9B];
    u8 subtype;
} ObjectInfo;

typedef struct GlobalMode {
    u8 pad00[8];
    s32 mode;
} GlobalMode;

extern const volatile Vec3 lbl_80238DA0;
extern const volatile Vec3 lbl_80238DAC;
extern volatile GlobalMode lbl_803003C8;
extern s32 lbl_8064D18C;
extern double lbl_8064E220;
extern float lbl_8064E228;
extern float lbl_8064E22C;
extern float lbl_8064E230;
extern float lbl_8064E234;
extern float lbl_8064E238;

extern void *fn_80201B9C();
extern void *fn_80201B8C();
extern void *fn_80201BC8();
extern void *fn_8011F114();
extern s32 fn_801A7570(void*);
extern void* fn_80205288(void*);
extern int fn_80201B54();
extern int fn_8011EB04(void *);
#define fn_8011EB04(a) fn_8011EB04((void *)(a))
extern void* fn_80201C24();
extern u32 fn_80157C80(void*);
extern int fn_80201EB8();
extern int fn_80201B4C(void*);
extern int fn_80201B64(void*);
extern unsigned long long fn_8020123C();
extern u32 fn_80178E94(Vec3*, Vec3*);
extern s32 fn_80036A1C(void*, s32, s32*, Vec3*);
extern u8 fn_80204434(void*, Vec3*, s32, float);
extern u32 fn_800361F8(ObjectInfo*);
extern void* fn_80201BC0(void*);

void* fn_800365C8(register void* source, register void* query)
{
    register void* candidate;
    register State* state;
    register void* source_transform;
    register void* linked;
    register ObjectInfo* info;
    register s32 candidate_id;
    register s32 source_id;
    register s32 previous_id;
    register s32 query_value;
    register s32 subtype;
    register s32 path_ok;
    register u32 distance;
    register void* selected;
    register float best_distance;
    Vec3 source_position;
    Vec3 candidate_position;
    Vec3 path_position;
    Vec3 temporary;
    Vec3* position;
    s32 path_value;

    candidate = fn_80201B9C();
    source_position = lbl_80238DA0;
    best_distance = lbl_8064E228;
    selected = 0;
    state = ((ObjectInfo*)fn_80201B8C(source))->state;
    source_transform = fn_80201BC8(source);
    if (source_transform != 0) {
        fn_8011F114(&temporary, source_transform);
        position = &temporary;
    } else {
        position = &source_position;
    }
    source_position = *position;
    query_value = fn_801A7570(query);
    linked = fn_80205288(source);
    if (linked != 0) {
        info = fn_80201B8C(linked);
    } else {
        info = 0;
    }
    subtype = info != 0 ? info->subtype : 19;
    source_id = fn_80201B54(source);

    if (linked != 0) {
        void* transform = fn_80201BC8(linked);
        previous_id = transform != 0 ? fn_8011EB04(transform) : -1;
    } else {
        previous_id = -1;
    }
    if (linked == 0 || previous_id == 99 || previous_id == 198 || previous_id == 241) {
        return 0;
    }

    if (subtype == 18) {
        void* value = fn_80201C24(linked);
        if ((fn_80157C80(value) & 0x20) != 0 ||
            (fn_80157C80(value) & 0x80) != 0) {
            return 0;
        }
        best_distance = lbl_8064E22C;
    }

    while (candidate != 0 && selected == 0) {
        info = fn_80201B8C(candidate);
        candidate_position = lbl_80238DAC;
        candidate_id = fn_80201B54(candidate);
        {
            void* transform = fn_80201BC8(candidate);
            if (transform != 0) {
                fn_8011F114(&temporary, transform);
                position = &temporary;
            } else {
                position = &candidate_position;
            }
        }
        candidate_position = *position;

        if (fn_80201EB8(candidate) == lbl_8064D18C &&
            (fn_80201B4C(candidate) == 0 || fn_80201B4C(candidate) == 1) &&
            candidate != source &&
            (fn_80201B64(candidate) == 8 || fn_80201B64(candidate) == 9)) {
            s32 candidate_message_id = fn_80201B54(candidate);
            if ((fn_8020123C(0xC1, source_id, candidate_message_id, 0) & 0xFFFFFFFFULL) != 0 &&
                (float)fn_80178E94(&candidate_position, &source_position) < lbl_8064E230) {
                path_ok = fn_80036A1C(candidate, query_value, &path_value, &path_position);
                distance = fn_80178E94(&path_position, &source_position);
                if (path_ok != 0 && (float)distance < best_distance &&
                    fn_80204434(source_transform, &path_position, 0, lbl_8064E234) != 0) {
                    state->source_id = candidate_message_id;
                    state->timer = 180;
                    selected = candidate;
                    state->source_position = source_position;
                } else if (path_ok != 0 && candidate_message_id == state->source_id) {
                    best_distance += lbl_8064E238;
                    if ((float)distance < best_distance) {
                        selected = candidate;
                    }
                }

                if (selected != 0) {
                    if (lbl_803003C8.mode == 5 && info != 0 && fn_800361F8(info) == 0 &&
                        (fn_8020123C(0xC2, source_id, candidate_id, 0) & 0xFFFFFFFFULL) != 0) {
                        selected = 0;
                    } else {
                        state->target_id = candidate_message_id;
                        state->target_position = path_position;
                        state->path_value = path_value;
                        break;
                    }
                }
            }
        }
        candidate = fn_80201BC0(candidate);
    }
    return selected;
}
