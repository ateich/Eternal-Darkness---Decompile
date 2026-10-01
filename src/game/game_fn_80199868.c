typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct Point {
    u8 flag0;
    u8 pad1[9];
    s16 position[3];
    u8 value10[0xC];
    s16 value1C;
    u8 pad1E[0xD];
    u8 state2B[0xD];
} Point;

typedef struct Config {
    u8 period;
    u8 count;
    u8 start;
    u8 value3;
    u8 value4;
    u8 pad5[0x17];
    u32 actor;
    void* targets[2];
    void* sources[2];
} Config;

typedef struct Effect {
    u8 pad0;
    u8 count;
    u8 pad2[2];
    u8 value4;
    u8 pad5[5];
    u16 frame;
    u16 last;
    u8 padE[0x14];
    u16 state;
    u8 list[0x28];
    Point* points;
    u8 pad50[0x3C];
    Config config;
} Effect;

typedef struct Result {
    u32 unused[2];
    float x;
    float y;
    float z;
    u32 padding[5];
} Result;

extern void fn_8018E230(void*, void*, int, u8, u8, u8);
extern void fn_8018E260(void*, u8, u8);
extern void* fn_80201814(u32);
extern void* fn_80201BC8(void);
extern void fn_8011F6A4(void*, void*, void*, int, void*, int);
extern void fn_80180518(void*, u8, int);
extern u8 fn_8018E26C(void*, void*);
extern int fn_80180430(void*, u8);
extern int fn_80180454(void*);
extern void fn_8017DCA8(void*, s16, void*);

int fn_80199868(Effect* object)
{
    int step;
    Config* config = &object->config;
    Result result;
    int count;
    int first;
    int index;
    Point* point;
    int i;
    Point* attach_point;
    Point* current;
    int attach_first;
    int attach_index;
    int group;
    void* actor;

    if (object->frame % config->period == 0) {
        first = object->frame / config->period;
        first *= config->count;
        point = &object->points[first];
        for (index = first; index < first + config->count; index++) {
            fn_8018E230(point, point->state2B, 2, config->value3, object->value4,
                        config->value4);
            fn_8018E260(point, config->value3, config->value4);
            point++;
        }
    }

    if (object->frame >= config->start &&
        (object->frame - config->start) % config->period == 0 &&
        object->frame <= object->last &&
        fn_80201814(config->actor) != 0) {
        actor = fn_80201BC8();
        step = 0;
        group = (object->frame - config->start) / config->period;
        attach_first = group * config->count;
        attach_point = &object->points[attach_first];
        for (attach_index = attach_first; attach_index < attach_first + config->count;
             attach_index++, step++) {
            fn_8011F6A4(actor, config->targets[step], config->sources[step], -1, &result, 1);
            attach_point->position[0] = result.x;
            attach_point->position[1] = result.y;
            attach_point->position[2] = result.z;
            fn_80180518(object->list, attach_index, 1);
            attach_point++;
        }
    }

    current = object->points;
    count = object->count;
    for (i = 0; i < count; i++) {
        if (current->flag0 != 0) {
            if (!fn_8018E26C(current, current->state2B)) {
                fn_80180518(object->list, i, 0);
            }
        }
        if (fn_80180430(object->list, i)) {
            fn_8017DCA8(current->position, current->value1C, current->value10);
        }
        current++;
    }

    object->frame++;
    if (object->frame > object->last && fn_80180454(object->list)) {
        object->state = 8;
    }
    return 0;
}
