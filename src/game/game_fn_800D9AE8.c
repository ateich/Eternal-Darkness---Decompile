typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Actor {
    u8 pad0[0x84];
    u16 flags;
    u8 pad86[0x16];
    void *effects[3];
    void *handle;
} Actor;

extern void fn_8019B134(void *, int);
extern void *fn_80156938();
extern int fn_80193860(void);
extern void fn_801938D8(void *, int);

int fn_800D9AE8(Actor *actor)
{
    unsigned int i;

    if ((actor->flags & 4) != 0) {
        for (i = 0; i < 3; i++) {
            if (actor->effects[i] != 0) {
                fn_8019B134(actor->effects[i], 0);
                actor->effects[i] = 0;
            }
        }
        actor->flags &= ~4;
    }
    if ((actor->flags & 8) != 0) {
        void *value = fn_80156938(actor->handle);
        int state = fn_80193860();
        fn_801938D8(value, state | 0x40000);
        actor->handle = 0;
        actor->flags &= ~8;
    }
    return 0;
}
