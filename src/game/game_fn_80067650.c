typedef signed int s32;
typedef unsigned int u32;

typedef struct Actor {
    u32 flags;
    unsigned char pad[0xBC];
    s32 target;
} Actor;

extern s32 fn_80036D38(s32 context);
extern int fn_80201B54();
extern void* fn_80201B94();
extern void fn_80201DD8(void *object, s32 value);

void fn_80067650(s32 context)
{
    Actor *actor = (Actor *)fn_80036D38(context);

    fn_80201B54(context);
    if (actor->target != 0) {
        void *object = fn_80201B94(context);
        if (object != 0)
            fn_80201DD8(object, 0);
    }
    actor->flags &= ~0x00400000U;
    actor->target = 0;
}
