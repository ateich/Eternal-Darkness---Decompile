typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State {
    u32 flags;
} State;

typedef struct Owner {
    u8 pad[0x8C];
    State *state;
} Owner;

extern void *fn_80201B9C();
extern void *fn_80201B8C();
extern void *fn_80201BC0(void *);

void fn_800C63D8(void)
{
    void *item;

    item = fn_80201B9C();
    while (item != 0) {
        Owner *owner = ((Owner *)fn_80201B8C(item));
        State *state = owner != 0 ? owner->state : 0;
        if (state != 0) {
            state->flags &= ~(1UL << 16);
        }
        item = fn_80201BC0(item);
    }
}
