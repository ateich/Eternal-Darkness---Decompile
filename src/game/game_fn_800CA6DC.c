typedef unsigned char u8;
typedef unsigned int u32;

typedef union EventArguments {
    u8 raw[0x1C];
    u8 byte_value;
    u32 word_value;
    struct {
        void *value;
        u32 handle;
    } object;
    struct {
        void *value;
        u8 flag;
    } flagged_object;
} EventArguments;

typedef struct Event {
    u32 flags;
    EventArguments arguments;
} Event;

extern u32 fn_80201B54(void *);
extern void fn_800CA660(void *, u32 *);
extern int fn_800CA530(void *);
extern int fn_801D0794(u32, int, u32, EventArguments *, int, int,
                      int (*)(void *), u32);

#pragma use_lmw_stmw on
int fn_800CA6DC(void *object, int kind, u32 flags, void *value, int byte_value)
{
    Event event;
    u32 handle;

    event.flags = flags | kind;
    handle = fn_80201B54(object);

    switch (kind) {
    case 0x300:
        event.arguments.object.value = value;
        event.arguments.object.handle = handle;
        break;
    case 0x1010:
        event.arguments.flagged_object.value = value;
        event.arguments.flagged_object.flag = 0;
        break;
    case 0x410:
        event.arguments.byte_value = (u8)byte_value;
        break;
    case 0x810:
        event.arguments.word_value = (u32)value;
        break;
    case 0x480:
    case 0x500:
    case 0x1040:
        break;
    }

    fn_800CA660(object, &event.flags);
    return fn_801D0794(event.flags, 0, handle, &event.arguments, 0, 0,
                       fn_800CA530, (handle << 8) | 0x78);
}
