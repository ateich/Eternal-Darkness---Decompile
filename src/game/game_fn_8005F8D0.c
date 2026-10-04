typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Pair {
    s32 first, second;
} Pair;

typedef struct QueryResult {
    u8 pad00[8];
    Vec3 direction;
    u8 pad14[0x14];
} QueryResult;

typedef struct SourceObject {
    u8 pad00[0x94];
    s32 object_id;
} SourceObject;

typedef struct EffectConfig {
    float reset_time;
    float duration;
    s32 count;
    s32 random_min;
    s32 random_max;
    float phase_step;
    float unk18;
    float cooldown_step;
    u8 unk20;
    u8 sound;
    u8 pad22[2];
} EffectConfig;

extern u8 lbl_8030F820[];
extern s32 lbl_8064C888;
extern s8 lbl_8064C590;
extern s32 lbl_8064D18C;
extern const float lbl_8064E5B8;
extern const float lbl_8064E5BC;
extern const float lbl_8064E5D4;
extern const float lbl_8064E5DC;

extern s32 fn_80066D04(void *, s32);
extern s32 fn_8005EE9C(s32, s32, s32 *);
extern void fn_8011F114();
extern s32 fn_8011F6A4(void *, s32, s32, s32, QueryResult *, s32);
extern unsigned int fn_800FBFB0(void);
extern void fn_8005F758(void *, s32, Vec3 *, s32, s32, s32, u8, u8, s32, u8);
extern void fn_801AAE68(float, s32, s32, s32, Vec3 *, s32, s32, s32, u16, s32);
extern void fn_801D62D0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32, s32, s32, s32);
extern void fn_80211A6C();
extern void fn_80211AAC(Vec3 *, Vec3 *);
extern void fn_80211A90(Vec3 *, Vec3 *, float);
extern void fn_80211A48(Vec3 *, Vec3 *, Vec3 *);
extern s32 fn_801D3A24(s32, s32);
extern void fn_8015295C(Vec3 *, Vec3 *, s32, s32, s32);
extern void fn_8020104C(int, void*, void*, int, float);

static EffectConfig effect_config[5] = {
    { 240.0f, 1.0f, 1, 120, 140, 1.0f, 0.0f, 1.0f, 1, 60 },
    { 35.0f, 42.0f, 1, 60, 80, 1.0f, 1.5f, 1.0f, 2, 60 },
    { 35.0f, 42.0f, 1, 30, 50, 1.0f, 1.5f, 1.0f, 3, 60 },
    { 31.0f, 43.0f, 2, 25, 30, 1.0f, 1.5f, 1.0f, 4, 60 },
    { 25.0f, 43.0f, 3, 10, 25, 1.0f, 1.5f, 1.0f, 5, 60 },
};

static Pair effect_pairs_a[8] = {
    { 2, 5 }, { 3, 2 }, { 4, 1 }, { 2, 1 }, { 3, 4 }, { 2, 3 }, { 3, 1 }, { 5, 1 },
};

static Pair effect_pairs_b[8] = {
    { 24, 0 },  { 23, 24 }, { 0, 31 },  { 24, 31 },
    { 23, 0 },  { 24, 23 }, { 23, 31 }, { 0, 31 },
};

void fn_8005F8D0(void *owner, void *entry, void *manager, SourceObject *source,
                 u8 *state_object, s8 config_kind, Vec3 *position,
                 s32 final_value, s32 force_mode)
{
    QueryResult primary;
    QueryResult secondary;
    Vec3 copied_direction;
    Vec3 source_position;
    Vec3 direction;
    s32 query_three;
    s32 query_two;
    u16 range;
    s32 state;

    query_two = fn_80066D04(entry, 2);
    query_three = fn_80066D04(entry, 3);
    state = fn_8005EE9C(!query_three, !query_two,
                        (s32 *)(state_object + 0x78));
    fn_8011F114(&source_position, manager);

    if (position != 0) {
        secondary.direction.x = position->x;
        secondary.direction.x = position->y;
        secondary.direction.x = position->z;
    }

    if (fn_8011F6A4(manager, effect_pairs_b[state].first,
                    effect_pairs_a[state].first, -1, &primary, 1) == -1) {
        return;
    }
    if (position == 0 &&
        fn_8011F6A4(manager, effect_pairs_b[state].second,
                    effect_pairs_a[state].second, -1, &secondary, 1) == -1) {
        return;
    }

    range = (u16)(effect_config[config_kind].random_min +
                  (int)fn_800FBFB0() % (effect_config[config_kind].random_max -
                                   effect_config[config_kind].random_min));

    if (position != 0) {
        s32 out_of_range;

        out_of_range = ++lbl_8064C888 < 0 || lbl_8064C888 >= 5;
        lbl_8064C888 = out_of_range ? 0 : lbl_8064C888;
        fn_8005F758(lbl_8030F820 + lbl_8064C888 * 0xC4, source->object_id,
                    position, (s32)owner, effect_pairs_b[state].first,
                    effect_pairs_a[state].first, 5, 2, 0, 4);
        fn_801AAE68(lbl_8064E5BC, 0x289, 0x5A, 0, &source_position, 2, 2,
                    0, (u16)lbl_8064D18C, 0);
    } else {
        s32 id = (s32)owner;

        fn_801D62D0(id, effect_pairs_b[state].first,
                    effect_pairs_a[state].first, id, effect_pairs_b[state].second,
                    effect_pairs_a[state].second, source->object_id, 0, 0,
                    effect_config[config_kind].unk20, 4, 2, 2, 1, 0, 1, 0x11, 8, 4, 0x20, 0,
                    0, range, 0x42040, 0x2030, (u8)(force_mode ? 4 : 0xC));
        if (lbl_8064C590++ < 2) {
            fn_801AAE68(lbl_8064E5BC, 0xBE, effect_config[config_kind].sound, 0,
                        &source_position, 2, 2, 0, (u16)lbl_8064D18C, 0);
        }
    }

    copied_direction = primary.direction;
    fn_80211A6C(&secondary.direction, &primary.direction, &direction);
    if (lbl_8064E5DC != direction.x || lbl_8064E5DC != direction.y ||
        lbl_8064E5DC != direction.z) {
        fn_80211AAC(&direction, &direction);
        fn_80211A90(&direction, &direction, lbl_8064E5B8);
        fn_80211A48(&primary.direction, &direction, &copied_direction);
        fn_8015295C(&primary.direction, &copied_direction,
                    fn_801D3A24(source->object_id, 0x31), 4, 2);
    }

    if (position == 0) {
        fn_8020104C(0xF1, owner, owner, state, lbl_8064E5D4);
    } else {
        fn_8020104C(0xF5, owner, owner, final_value, lbl_8064E5D4);
    }
}
