typedef unsigned char u8;
typedef unsigned int u32;

typedef struct EventPayload {
    u32 second;
    u8 pad[0x1C];
    u32 first;
} EventPayload;

extern u32 fn_801DE5C4(void *);
extern u32 fn_801DE5CC(void *);
extern void fn_8020123C(u8, u32, u32, EventPayload *);

int fn_800CA554(register void *object, register u32 packed)
{
    register u32 group;
    EventPayload payload;

    group = packed >> 8;

    payload.first = fn_801DE5C4(object);
    payload.second = fn_801DE5CC(object);
    fn_8020123C((u8)packed, group, group, &payload);
    return 1;
}
