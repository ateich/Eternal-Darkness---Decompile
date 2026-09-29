typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Input801F15D0 {
    u8 pad00[0x14];
    s16 limit0;
    s16 limit1;
    s16 limit2;
    u8 count;
} Input801F15D0;

typedef struct Item801F15D0 {
    u8 pad00[4];
    Vec3 point;
    u8 pad10[4];
    Vec3 direction;
    u8 pad20[0x18];
} Item801F15D0;

typedef struct IndexRecord801F15D0 {
    u8 pad00[0x58];
    u8 index;
    u8 pad59[3];
} IndexRecord801F15D0;

typedef struct Group801F15D0 {
    u8 pad00[0x20];
    u16 count;
    u8 pad22[2];
    IndexRecord801F15D0* indices;
    Item801F15D0* items;
} Group801F15D0;

typedef struct ColorItem801F15D0 {
    u8 pad00[0xC];
    u8 r, g, b, a;
    u8 pad10[4];
} ColorItem801F15D0;

typedef union DoubleBits801F15D0 {
    double value;
    struct {
        u32 high;
        u32 low;
    } bits;
} DoubleBits801F15D0;

extern s32 fn_8015C71C(s32);
extern Group801F15D0* fn_8015C28C(s32);
extern u32 fn_801ECBB4(void);
extern s32 fn_801F2370(Input801F15D0*, Vec3*, s32, ColorItem801F15D0*);
extern u32 fn_80178F14(s32, s32, s32, s32, s32, s32);
extern void fn_80211B44(Vec3*, Vec3*);
extern const double lbl_80651350;
extern const double lbl_80651360;
extern const float lbl_806513B8;

/* Keep conversions local to this translation unit and reuse their storage. */
static inline float unsigned_float(u32 value, DoubleBits801F15D0* bits)
{
    bits->bits.low = value;
    bits->bits.high = 0x43300000;
    return (float)(bits->value - lbl_80651350);
}

static inline float signed_float(s32 value, DoubleBits801F15D0* bits)
{
    bits->bits.low = ((u32)value) ^ 0x80000000;
    bits->bits.high = 0x43300000;
    return (float)(bits->value - lbl_80651360);
}

/* NonMatching: shared-constant conversions still emit fsub/frsp pairs. */
s32 fn_801F15D0(Vec3* point, s32 group_id, Input801F15D0* input,
                 s32* count_out, ColorItem801F15D0* colors)
{
    DoubleBits801F15D0 blue_bits;
    DoubleBits801F15D0 green_bits;
    DoubleBits801F15D0 red_bits;
    u32 packed;
    float red_scale;
    float green_scale;
    float blue_scale;

    s32 group_index;
    Group801F15D0* group;
    s32 result;
    s32 i;
    Group801F15D0* work_group;

    group_index = fn_8015C71C(group_id);
    packed = fn_801ECBB4();
    red_scale = unsigned_float(((u8*)&packed)[0], &red_bits) / lbl_806513B8;
    green_scale = unsigned_float(((u8*)&packed)[1], &green_bits) / lbl_806513B8;
    blue_scale = unsigned_float(((u8*)&packed)[2], &blue_bits) / lbl_806513B8;
    if (group_index == -1) {
        return -1;
    }

    group = fn_8015C28C(group_index);
    if (group_index == 2) {
        fn_8015C28C(3);
    } else {
        fn_8015C28C(2);
    }
    if (group != 0 && *(s8*)((u8*)group + 0x8143) != 0) {
        work_group = (Group801F15D0*)((u8*)group + 0xA0);
    }

    if (input == 0) {
        return -1;
    }
    *count_out = input->count;
    if (*count_out > 4) {
        *count_out = 4;
    }
    result = fn_801F2370(input, point, *count_out, colors);
    if (result == -1) {
        return -1;
    }

    for (i = 0; i < work_group->count; i++) {
        Item801F15D0* item = &work_group->items[work_group->indices[i].index];
        Vec3* item_point = &item->point;
        u32 distance;
        float distance_float;

        distance = fn_80178F14((s32)point->x, (s32)point->y, (s32)point->z,
                                   (s32)item->point.x, (s32)item->point.y,
                                   (s32)item->point.z);
        distance_float = unsigned_float(distance, &red_bits);
        if (distance_float <= signed_float(input->limit0, &green_bits) ||
            distance_float <= signed_float(input->limit1, &green_bits) ||
            distance_float <= signed_float(input->limit2, &green_bits)) {
            fn_80211B44(&item->direction, item_point);
            fn_80211B44(&item->direction, point);
        }
    }

    for (i = 0; i < *count_out; i++) {
        colors[i].r = (u8)(red_scale * unsigned_float(colors[i].r, &red_bits));
        colors[i].g = (u8)(green_scale * unsigned_float(colors[i].g, &green_bits));
        colors[i].b = (u8)(blue_scale * unsigned_float(colors[i].b, &blue_bits));
    }
    return result;
}
