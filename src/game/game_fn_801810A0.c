typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

typedef struct FloatCoord3 {
    float x;
    float y;
    float z;
} FloatCoord3;

typedef struct Entry801810A0 {
    u8 pad00[8];
    s16 field08;
    s16 x;
    s16 y;
    s16 z;
    u8 pad10[0x18];
    u8 render[0x10];
} Entry801810A0;

typedef struct State801810A0 {
    u8 index;
    u8 field01;
    u8 field02;
    u8 field03;
    u8 mode;
    u8 field05;
    u16 field06;
    u16 field08;
    u16 stride;
    s16 field0C;
    u16 selectors[0x11];
    float angle_step;
    u8 pad34[0x2C];
    FloatCoord3 transform_source;
    FloatCoord3 transform_angles;
    FloatCoord3 transform_result;
    u8 pad84[4];
} State801810A0;

typedef struct Object801810A0 {
    u8 pad00;
    u8 count;
    u8 pad02[0xE];
    ShortCoord3 base;
    u8 pad16[0xE];
    u8 control[0x28];
    Entry801810A0* entry;
    u8 pad50[0x3C];
    State801810A0 state;
} Object801810A0;

extern u32 lbl_80651CD8;
extern u16 lbl_80651CDC;
extern const float lbl_8065095C;
extern const float lbl_8065096C;
extern const double lbl_80650970;
extern u32 lbl_80650968;

extern void* memcpy(void*, const void*, unsigned int);
extern void fn_8018163C(Entry801810A0*, ShortCoord3*, u8, u16);
extern void fn_80211380(FloatCoord3*, FloatCoord3*, float);
extern void fn_80211710(FloatCoord3*, FloatCoord3*, FloatCoord3*);
extern u32 fn_800FBFB0(void);
extern void fn_8018E230(Entry801810A0*, u8*, int, u8, int, int);
extern void fn_8018E260(Entry801810A0*, int, int);
extern void fn_801806D4(u8*, u32*, int);
extern void fn_80180518(u8*, u8, int);

void fn_801810A0(Object801810A0* object, u8* config)
{
    State801810A0* current;
    u8 outer_count;
    u8 inner_count;
    int outer;
    int inner;
    int outer_index;
    State801810A0* state;
    Entry801810A0* entry;
    FloatCoord3 position;
    ShortCoord3 work;
    float scale;
    float zero;

    inner_count = config[2];
    outer_count = object->count;
    state = &object->state;
    entry = object->entry;

    state->field0C = *(s16*)(config + 0xC);
    state->stride = *(u16*)(config + 6);
    state->field06 = *(u16*)(config + 8);
    state->field01 = config[0];
    state->index = 0;
    state->field02 = 1;
    state->angle_step = *(float*)(config + 0x18);
    state->field03 = inner_count;
    state->mode = config[3];
    state->field05 = config[4] & 0x1F;
    state->transform_angles = *(FloatCoord3*)(config + 0x34);
    state->transform_source = *(FloatCoord3*)(config + 0x34);
    memcpy(state->pad34, (u8*)object + 0x10, 6);

    scale = lbl_8065096C;
    zero = lbl_8065095C;
    current = state;
    outer = 0;
    inner = 0;
    outer_index = 0;
    while (outer < outer_count) {
        while (inner < inner_count) {
            *(u32*)&work = lbl_80651CD8;
            *(u16*)((u8*)&work + 4) = lbl_80651CDC;
            work.z = entry->z;
            current->selectors[0] = state->field06;
            fn_8018163C(entry, &work,
                        (u8)((int)((float)inner * state->angle_step) & 0x3F),
                        current->selectors[0]);

            position.x = entry->x;
            position.y = entry->y;
            position.z = entry->z;
            if (state->transform_source.z < zero) {
                fn_80211380(&state->transform_result, &state->transform_source,
                            scale * -state->transform_source.z);
                fn_80211710(&state->transform_result, &position, &position);
            }
            entry->x = (s16)(position.x + object->base.x);
            entry->y = (s16)(position.y + object->base.y);
            entry->z = (s16)position.z;
            entry->field08 += state->stride * outer_index;
            entry++;
            inner++;
        }
        inner = 0;
        current = (State801810A0*)((u8*)current + 2);
        outer_index++;
        outer++;
    }

    entry = object->entry;
    outer = 0;
    while (outer < inner_count) {
        if (state->mode == 4) {
            fn_8018E230(entry, &entry->render[3], 4,
                        (u8)((fn_800FBFB0() & 7) * 0x14), 0xA, 0xF0);
            fn_8018E260(entry, 0xF0, 0x78);
        } else {
            u32 render = lbl_80650968;
            fn_801806D4((u8*)entry + 0x20, &render, 0);
        }
        fn_80180518(object->control, state->index, 1);
        entry++;
        state->index++;
        outer++;
    }
}
