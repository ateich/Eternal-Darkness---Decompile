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
    u32 flags;
} State;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    State* state;
    u8 pad90[8];
    s16 category;
} ObjectInfo;

extern const volatile Vec3 lbl_80238D88;
extern const volatile Vec3 lbl_80238D94;

extern s32 lbl_8064A80C;
extern float lbl_80650598;
extern void* fn_80201B9C(void);
extern ObjectInfo* fn_80201B8C(void*);
extern s32 fn_80201B54(void*);
extern s32 fn_80201B64(void*);
extern void* fn_80201BC8(void*);
extern s32 fn_80201B4C(void*);
extern s32 fn_80201EB8(void*);
extern void* fn_80201BC0(void*);
extern void fn_8011F114(Vec3*, void*);
extern u32 fn_80179004(Vec3*, Vec3*);
extern u32 fn_800361F8(ObjectInfo*);
extern u64 fn_8020123C(s32, s32, s32, s32);

void* fn_80036374(register void* object)
{
    register void* candidate;
    register s32 object_id;
    register s32 kind;
    register s32 candidate_id;
    register u32 flags;
    register ObjectInfo* info;
    register const volatile Vec3* default_position;
    Vec3 object_position;
    Vec3 candidate_position;
    Vec3 temporary;
    Vec3 candidate_temporary;
    void* position;
    Vec3* selected;
    ObjectInfo* candidate_info_temp;

    candidate = fn_80201B9C();
    object_position = lbl_80238D88;
    info = fn_80201B8C(object);
    object_id = fn_80201B54(object);
    position = fn_80201BC8(object);
    if (position != 0) {
        fn_8011F114(&temporary, position);
        selected = &temporary;
    } else {
        selected = &object_position;
    }
    object_position = *selected;

    if (info->category != 44) {
        return 0;
    }

    default_position = &lbl_80238D94;
    while (candidate != 0) {
        candidate_info_temp = fn_80201B8C(candidate);
        info = candidate_info_temp;
        kind = fn_80201B64(candidate);
        candidate_position = *default_position;
        position = fn_80201BC8(candidate);
        if (position != 0) {
            fn_8011F114(&candidate_temporary, position);
            selected = &candidate_temporary;
        } else {
            selected = &candidate_position;
        }
        candidate_position = *selected;
        candidate_id = fn_80201B54(candidate);

        if (info != 0) {
            ObjectInfo* object_info = fn_80201B8C(object);
            if (object_info != 0 && object_info->state != 0) {
                flags = object_info->state->flags;
            }
        }

        if ((fn_80201B4C(candidate) == 0 || fn_80201B4C(candidate) == 1) &&
            candidate != object && fn_80201EB8(candidate) == lbl_8064A80C &&
            (flags & 0x4000) == 0 &&
            (kind == 8 || kind == 31) &&
            (float)fn_80179004(&candidate_position, &object_position) < lbl_80650598 &&
            info != 0 && fn_800361F8(info) == 0) {
            u32 message_result = fn_8020123C(0xC2, object_id, candidate_id, 0) & 0xFFFFFFFFULL;
            if (message_result != 0) {
            return candidate;
            }
        }
        candidate = fn_80201BC0(candidate);
    }
    return 0;
}
