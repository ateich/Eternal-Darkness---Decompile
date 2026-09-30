typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

typedef struct Work {
    u8 pad0[0xC];
    int owner;
    u8 pad10[0xAC];
    void* value;
    int runtime;
    u8 flags;
    u8 padC5[3];
    void* control;
    u8 padCC[0xC0];
    void* effect;
    u8 pad190[0xC0];
    u8* samples;
    u8 pad254[0xD9C];
    u8 status;
} Work;

extern int lbl_8064D18C;
extern float lbl_80651248;
extern float lbl_8065124C;
extern void* fn_80201814(int);
extern int fn_80201B64(void*);
extern void fn_8020123C(int, void*, void*, void*);
extern u32 fn_801A39A8(void*);
extern void fn_801A39B8(void*, void*);
extern void fn_801A39D4(void*, u8);
extern void fn_801D0E78(Work*);
extern int fn_80201EB8(void*);
extern ShortCoord3* fn_8017FDE4(void*);
extern ShortCoord3* fn_8017FDA8(void*, int);
extern void fn_801499C4(void*, ShortCoord3*, int, int, int);
extern s16 fn_801A39B0(void*);
extern float* fn_801A3998(void*);
extern float fn_801A39A0(void*);
extern void fn_8017E850(ShortCoord3*, ShortCoord3*, s16, float*, float);
extern void fn_8017E958(ShortCoord3*, ShortCoord3*, s16, float);
extern void fn_80185108(void*);
extern void fn_801851A0(void*, const void*);

void fn_801E3644(Work* work)
{
    u32 flags;
    u32 effect_flags;
    float initial_angle;
    float increment;
    void* owner;
    void* effect_object;
    void** attachment;
    ShortCoord3* point;
    void* effect_a;
    ShortCoord3* loop_point;
    u8* sample_table;
    void* effect;
    u8 final_flags;
    int is_current;
    void* effect_b;
    ShortCoord3* center;
    u8 count;
    s16 distance;
    float* angle;
    int index;

    owner = fn_80201814(work->owner);

    if (owner == 0 || fn_80201B64(owner) == 8) {
        fn_8020123C(57, work->value, work->value, 0);
    }

    if ((work->flags & 1) == 0) {
        if (work->effect != 0 &&
            (effect = *(void**)((u8*)work->effect + 0x88)) != 0) {
            flags = fn_801A39A8(effect);
            if (work->control != 0) {
                final_flags = (u8)(flags | 4);
                fn_801A39B8(effect, work->control);
            } else {
                final_flags = (u8)(flags & ~1);
            }
            fn_801A39D4(effect, final_flags);
        }
        fn_801D0E78(work);
        return;
    }

    is_current = fn_80201EB8(owner) == lbl_8064D18C;

    if ((work->flags & 4) != 0) {
        if (work->effect != 0 &&
            (effect_a = *(void**)((u8*)work->effect + 0x88)) != 0) {
            effect_flags = fn_801A39A8(effect_a);
            fn_801A39D4(effect_a, effect_flags | 0x40);
        }
        work->flags = work->flags & ~4;
    } else if ((work->flags & 2) != 0) {
        if (work->effect != 0 &&
            (effect_b = *(void**)((u8*)work->effect + 0x88)) != 0) {
            effect_flags = fn_801A39A8(effect_b);
            fn_801A39D4(effect_b, effect_flags | 0x20);
        }
        work->flags = work->flags & ~2;
    }

    if ((is_current && work->runtime != lbl_8064D18C) ||
        (work->status & 2)) {
        if (work->effect != 0) {
            effect_object = *(void**)((u8*)work->effect + 0x88);
            sample_table = work->samples;
            center = fn_8017FDE4(effect_object);
            if (work->status & 2) {
                fn_801499C4(owner, center, 0, 0, 0);
            }

            count = sample_table[0];
            distance = fn_801A39B0(effect_object);
            angle = fn_801A3998(effect_object);
            *angle = lbl_80651248;
            initial_angle = fn_801A39A0(effect_object);
            increment = lbl_8065124C / (float)count;

            point = fn_8017FDA8(effect_object, 0);
            fn_8017E850(point, center, distance, angle, initial_angle);
            fn_80185108(*(void**)(sample_table + 0x88));
            fn_801851A0(*(void**)(sample_table + 0x88), point);

            attachment = (void**)(sample_table + 0x8C);
            for (index = 1; index < count; attachment++, index++) {
                loop_point = fn_8017FDA8(effect_object, index);
                fn_8017E958(loop_point, center, distance,
                            *angle + (float)index * increment);
                fn_80185108(*attachment);
                fn_801851A0(*attachment, loop_point);
            }
        }
        work->runtime = lbl_8064D18C;
        work->status = work->status & ~2;
    }
}
