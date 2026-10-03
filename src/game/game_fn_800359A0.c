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
    u32 flags00;
    u8 pad04[0xBC];
    s32 ownerC0;
    u8 padC4[0x86];
    s16 range14A;
} State;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    State* state8C;
    u8 pad90[4];
    s32 value94;
    u8 pad98[6];
    u8 kind9E;
    u8 kind9F;
} ObjectInfo;

extern s32 lbl_8064E208;
extern double lbl_8064E210;
extern int fn_80201B54();
extern void *fn_80201BC8();
extern void* fn_80201B94();
extern State* fn_80036D38(void*);
#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS void*, void*
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern void *fn_80201B8C();
extern unsigned int fn_80036D5C(void*);
extern int fn_80201B44();
extern void* fn_80201C48(void*);
extern int fn_80201EB8();
extern s32 fn_80035958(void*);
extern unsigned long long fn_8020123C();
extern s32 fn_80201CD4(void*);
extern void fn_80201E60(void*, s32);
extern void fn_80201DD8(void*, s32);
extern void *fn_80201B9C();
extern s32 fn_800CAF7C(void*);
extern void *fn_80201814();
extern void* fn_80201BC0(void*);
extern u32 fn_80178E94(Vec3*, Vec3*);
extern u8 fn_80204434(void*, Vec3*, float, s32);
extern s32 fn_80035890(void*, void*, void*, Vec3*, Vec3*);

s32 fn_800359A0(register void* source, register void* requested)
{
    register s32 source_id;
    register void* source_value;
    register State* source_state;
    register ObjectInfo* source_info;
    register ObjectInfo* requested_info;
    register u32 source_flags;
    register u32 requested_flags;
    register s32 requested_id;
    register s32 requested_kind;
    register void* requested_object;
    register s32 source_type;
    register s32 source_special;
    register s32 requested_special;
    register s32 source_value94;
    register s32 requested_value94;
    register s32 direct_result;
    Vec3 source_position;
    Vec3 candidate_position;
    Vec3 requested_position;
    u32 source_mask;
    u32 context_mask;
    void* source_context;
    void* best;
    void* candidate_context;
    u32 best_distance;
    u32 context_flags;
    s32 requested_has_state;
    Vec3 requested_temporary;
    u32 message_result;

    register void* candidate;
    register u32 nearest;
    register s32 candidate_id;
    register ObjectInfo* info;
    register u32 flags;
    register u8 kind9e;
    register u8 kind9f;
    register void* value;
    register s32 type;
    register s32 value94;
    register u32 distance;

    direct_result = 0;
    requested_value94 = 0;
    source_id = fn_80201B54(source);
    source_value = fn_80201BC8(source);
    source_context = fn_80201B94(source);
    source_state = fn_80036D38(source);
    fn_80201E78(&source_position, source);
    source_info = fn_80201B8C(source);

    if (requested != 0) {
        requested_info = fn_80201B8C(requested);
    } else {
        requested_info = 0;
    }
    source_flags = fn_80036D5C(source);
    if (requested != 0) {
        requested_id = fn_80201B54(requested);
    } else {
        requested_id = 0;
    }
    requested_object = (void*)fn_80201B44();
    if (requested != 0) {
        requested_flags = fn_80036D5C(requested);
    } else {
        requested_flags = 0;
    }
    /* Retail discards this lookup; the context is still the B94 result. */
    fn_80201C48(source_context);
    source_type = fn_80201EB8(source);

    if (source_state != 0) {
        source_special = (source_state->flags00 >> 22) & 1;
    } else {
        source_special = 0;
    }
    requested_has_state = requested_info != 0 && requested_info->state8C != 0;
    if (requested_has_state) {
        requested_special = (requested_info->state8C->flags00 >> 22) & 1;
    } else {
        requested_special = 0;
    }

    if (source_flags & 0x80) {
        source_value94 = fn_80035958(source_info);
    } else {
        source_value94 = source_info->value94;
    }
    if ((requested_flags & 0x80) != 0 && requested_info != 0 &&
        requested_info->state8C != 0) {
        requested_value94 = fn_80035958(requested_info);
    } else if (requested_info != 0) {
        requested_value94 = requested_info->value94;
    }

    if (requested != 0 && source_context != 0 &&
        source_id != (s32)requested_object && (requested_flags & 0x80) == 0 &&
        (requested_flags & 0x8000) == 0 &&
        ((requested_info != 0 && requested_id != (s32)requested_object &&
          requested_value94 != source_value94) ||
         (source_special != 0 || requested_special != 0 ||
          requested_id == (s32)requested_object)) &&
        ((message_result = fn_8020123C(0x3B, source_id, requested_id, 0) &
                           0xFFFFFFFFULL),
         message_result == 1)) {
        if (!((source_flags & 0x1000) == 0 ||
              ((source_flags & 0x1000) != 0 &&
               requested_id == (s32)requested_object))) {
            goto fail;
        }
        if (source_special != 0 && requested_id == source_state->ownerC0 &&
            requested_special == 0) {
            goto fail;
        }
        {
            fn_80201E78(&requested_temporary, requested);
            requested_position = requested_temporary;
            direct_result = 1;
            source_flags = fn_80201CD4(source_context);
            if ((source_flags & 4) != 0) {
                direct_result = fn_80035890(source, requested, source_value,
                                           &source_position, &requested_position);
            }
            if (direct_result != 0) {
                fn_80201E60(source_context, source_flags | 1);
                fn_80201DD8(source_context, fn_80201B54(requested));
                return 1;
            }
            goto fail;
        }
    }

    if (source_context != 0 && source_id != (s32)requested_object) {
        candidate = fn_80201B9C();
        nearest = (u32)-1;
        best = 0;
        candidate_context = fn_80201C48(source_context);
        if (fn_800CAF7C(source) == 0) {
            return 0;
        }
        context_flags = fn_80201CD4(source_context);
        if ((context_flags & 1) != 0) {
            void* old = fn_80201814(candidate_context);
            if (old != 0 && source_type == fn_80201EB8(old) &&
                ((message_result = fn_8020123C(0x3B, source_id,
                                               (s32)candidate_context, 0) &
                                   0xFFFFFFFFULL),
                 message_result == 1)) {
                return 1;
            }
            context_flags &= ~1u;
            fn_80201E60(source_context, context_flags);
        }
        source_mask = source_flags & 0x1000;
        context_mask = context_flags & 4;

        while (candidate != 0) {
            candidate_id = fn_80201B54(candidate);
            info = fn_80201B8C(candidate);
            if (info != 0 && info->state8C != 0) {
                flags = fn_80036D5C(candidate);
                /* The requested target is no longer used on the scan path. */
                requested_special =
                    (info->state8C->flags00 >> 22) & 1;
                kind9e = info->kind9E;
                kind9f = info->kind9F;
                value = fn_80201BC8(candidate);
                type = fn_80201EB8(candidate);

                if (flags & 0x80) {
                    value94 = fn_80035958(info);
                } else {
                    value94 = info->value94;
                }
                if (source_type == type && (flags & 0x80) == 0 &&
                    (flags & 0x8000) == 0 &&
                    (info->kind9E == 1 || info->kind9E == 2) &&
                    (value94 != source_value94 ||
                     (candidate_id == (s32)requested_object && kind9e == 1 &&
                      kind9f == 1) ||
                     (requested_special != 0 &&
                      info->state8C->ownerC0 != source_id) ||
                     source_special != 0) &&
                    source_id != candidate_id &&
                    (source_mask == 0 ||
                     (source_mask != 0 && candidate_id == (s32)requested_object)) &&
                    (source_special == 0 || candidate_id != source_state->ownerC0)) {
                    fn_80201E78(&candidate_position, candidate);
                    distance = fn_80178E94(&source_position, &candidate_position);
                    if (fn_80204434(source_value, &candidate_position,
                                    *(float*)&lbl_8064E208 *
                                        (float)source_state->range14A,
                                    0) != 0 &&
                        distance < nearest &&
                        ((message_result = fn_8020123C(0x3B, source_id,
                                                      candidate_id, 0) &
                                           0xFFFFFFFFULL),
                         message_result == 1)) {
                        direct_result = 1;
                        if (context_mask != 0) {
                            direct_result = fn_80035890(source, candidate, source_value,
                                                       &source_position,
                                                       &candidate_position);
                        }
                        if (direct_result != 0) {
                            nearest = distance;
                            best = candidate;
                        }
                    }
                }
            }
            candidate = fn_80201BC0(candidate);
        }
        if (best != 0) {
            fn_80201DD8(source_context, fn_80201B54(best));
            return 1;
        }
        {
            void* old = fn_80201814(candidate_context);
            if (old != 0 && source_type == fn_80201EB8(old) &&
                ((message_result = fn_8020123C(0x3B, source_id,
                                               (s32)candidate_context, 0) &
                                   0xFFFFFFFFULL),
                 message_result == 1)) {
                return 1;
            }
        }
        fn_80201DD8(source_context, 0);
    }
fail:
    return 0;
}
