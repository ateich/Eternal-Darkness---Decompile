typedef signed int s32;
typedef unsigned int u32;

extern void *fn_80201BC8();
extern void* fn_80201B94();
extern u32 fn_80201CCC(void);
extern void fn_8012C478(void *actor, s32 kind, void *value);
extern void fn_80201E50(void *object, u32 flags);

void fn_8006ABF0(s32 object)
{
    void *actor;
    void *target;
    s32 flags;

    actor = fn_80201BC8();
    target = fn_80201B94(object);
    flags = fn_80201CCC();
    if (flags & 0x00100000) {
        fn_8012C478(actor, 15, 0);
        flags &= ~0x00100000;
    }
    if (flags & 0x00000100) {
        fn_8012C478(actor, 3, 0);
        flags &= ~0x00000100;
    }
    if (flags & 0x00000200) {
        fn_8012C478(actor, 2, 0);
        flags &= ~0x00000200;
    }
    if (flags & 0x00000400) {
        fn_8012C478(actor, 0, 0);
        flags &= ~0x00000400;
    }
    fn_80201E50(target, flags);
}
