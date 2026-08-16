typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct RuntimeState {
    u8 pad[0x104];
    u16 strength;
    u16 duration;
    s16 timer;
    u8 pad10A[2];
    u8 flags;
} RuntimeState;
typedef struct ActorInfo {
    u8 pad[0x98];
    s16 kind;
    u8 pad9A[4];
    u8 mode;
    u8 variant;
} ActorInfo;

extern s32 lbl_8064D18C;
extern u16 lbl_8064C8A0;
extern float lbl_8064C898;
extern float lbl_8064E720, lbl_8064E724, lbl_8064E728, lbl_8064E72C;
extern Vec3 lbl_80239060, lbl_8023906C;
extern u32 lbl_8064E714, lbl_8064E718, lbl_8064E71C, lbl_80651958;

extern int fn_80201EB8();
extern void fn_8012AB2C(void *);
extern void fn_8011F114();
extern unsigned long long fn_8020123C();
extern void fn_8020104C(s32, s32, s32, s32, float);
extern void *fn_80201B9C();
extern int fn_80038308(s32, s32, u16 *);
extern s32 *fn_800681C8(void);
extern s32 fn_80200C20(s32); extern int fn_80200C38();
extern void fn_80067D30(s32), fn_800389E0(s32, s32, s32, s32), fn_80067B6C(void);
extern void fn_800685A4(void *, s32);
extern void fn_8012C62C(void *, s32, u32 *, u32 *, u32 *, s32);
extern void fn_8014CCB0(void *, u32 *, s32), fn_8014D100(void *, u32 *, s32, s32);
extern u16 fn_800681A0(s32, s32);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void *fn_80201BC8();
extern int fn_80201B54();
extern u32 fn_80178E94(Vec3 *, Vec3 *);
extern void fn_8013F4D0(Vec3 *, Vec3 *, Vec3 *);
extern s32 fn_8014317C(Vec3 *, Vec3 *, void *, s32, s32);
extern void fn_80068074(s32), fn_800CA2C8(s32), fn_80068870(s32, void *, RuntimeState **, u16);
extern void fn_800CC860(s32, s32, s32), fn_800BE8D4(s32), fn_8011E174(s32, s32);
extern void fn_800A5390(s32, void *, ActorInfo *, s32, s32, s32, s32);
extern void fn_80067A18(s32), fn_80201D34(s32, s32), fn_80201D1C(s32, s32);

void fn_80068AAC(s32 source, s32 object_id, void *effect, RuntimeState **state,
                 ActorInfo *actor, s32 event)
{
    Vec3 effect_pos;
    Vec3 raised_pos;
    s32 owner_kind;
    s32 *objects;
    s32 event_value;
    s32 event_kind;
    s32 list_item;
    s32 iter;
    u16 duration;
    u16 strength;
    u16 result;
    u32 p0, p1, p2;

    result = 0;
    owner_kind = fn_80201EB8(object_id);
    fn_8012AB2C(effect);
    fn_8011F114(&effect_pos, effect);
    raised_pos = effect_pos;
    raised_pos.z += lbl_8064E720;
    if (owner_kind != lbl_8064D18C) {
        fn_8020123C(0x39, source, source, 0);
        return;
    }

    list_item = (s32)fn_80201B9C();
    fn_80038308(object_id, 0, &result);
    objects = fn_800681C8();
    event_value = fn_80200C20(event);
    event_kind = fn_80200C38(event);
    fn_80067D30(object_id);
    fn_800389E0(object_id, 0, 0, 1);
    fn_80067B6C();
    fn_800685A4(effect, 0);
    fn_800685A4(effect, 2);
    fn_800685A4(effect, 3);

    p2 = lbl_8064E718;
    p1 = lbl_8064E71C;
    p0 = lbl_80651958;
    fn_8012C62C(effect, 15, &p2, &p1, &p0, 4);
    p0 = lbl_8064E714;
    fn_8014CCB0(effect, &p0, 4);
    fn_8014D100(effect, &p0, 8, 1);

    if ((*state)->duration != 0 && (*state)->strength != 0) {
        duration = (*state)->duration;
        strength = (*state)->strength;
    } else {
        u16 level = fn_800681A0(object_id, 0);
        strength = level * 5 + 5;
        duration = level * 200 + 250;
    }
    if (actor->kind >= 0x40 && actor->kind < 0x43)
        strength = 0;

    if (event_kind != 0) {
        if (((*state)->flags & 2) == 0) {
            (*state)->flags |= 2;
            lbl_8064C898 = lbl_8064E724;
            for (iter = 0; iter < 12; iter++) {
                s32 candidate_id = objects[iter];
                if (candidate_id != 0 && candidate_id != event_value) {
                    void *candidate = fn_80201814(candidate_id);
                    RuntimeState **candidate_state = (RuntimeState **)((u8 *)fn_80201B8C(candidate_id) + 4);
                    fn_8020123C(0x44, source, candidate_id, 1);
                    fn_8020104C(0x43, source, candidate_id, 0, lbl_8064C898);
                    lbl_8064C898 += lbl_8064E728;
                    (*candidate_state)->duration = duration;
                    (*candidate_state)->strength = strength;
                    (void)candidate;
                }
            }
        }
        (*state)->flags &= (u8)~2;
        fn_80068074(object_id);
    }
    lbl_8064C8A0 = strength;

    while (list_item != 0) {
        void *info = fn_80201B8C(list_item);
        void *position = fn_80201BC8(list_item);
        Vec3 target_pos = lbl_8023906C;
        s32 target_kind;
        s32 target_owner;
        if (position != 0)
            fn_8011F114(&target_pos, position);
        target_kind = fn_80201EB8(list_item);
        target_owner = fn_80201B54(list_item);
        if (owner_kind == target_kind && position != 0 && info != 0 &&
            (((ActorInfo *)info)->mode == 1 || ((ActorInfo *)info)->mode == 2) &&
            fn_80178E94(&effect_pos, &target_pos) < duration && object_id != list_item) {
            Vec3 delta;
            target_pos.z += lbl_8064E720;
            fn_8013F4D0(&delta, &raised_pos, &target_pos);
            target_pos.z -= lbl_8064E720;
            if (!fn_8014317C(&delta, &target_pos, effect, 0, 3)) {
                s32 kind = lbl_8064D18C;
                if (!fn_80204508(list_item, object_id)) kind |= 0x80000000;
                fn_8020104C(0x0E, source, target_owner, kind, lbl_8064E72C);
            }
        }
        list_item = fn_80201BC0(list_item);
    }

    fn_800CA2C8(object_id);
    fn_80068870(object_id, effect, state, duration);
    fn_800CC860(object_id, 1, 0);
    fn_800BE8D4(source);
    if (actor->mode == 1 && actor->variant == 3) {
        fn_8011E174(0x40, 0);
        fn_800A5390(object_id, effect, actor, event, 1, 1, 1);
    } else {
        fn_8020104C(0x39, source, source, 0, lbl_8064E728);
        fn_80067A18(source);
        fn_80201D34(object_id, 0x15);
        fn_80201D1C(object_id, 1);
    }
}
