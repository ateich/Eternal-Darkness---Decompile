typedef unsigned char u8;

typedef struct Link {
    u8 pad0[0xC];
    void* pointerC;
} Link;

typedef struct Owner {
    u8 pad0[0x160];
    Link* link;
} Owner;

extern void* fn_80128E30(void*);

void* fn_8012915C(Owner* owner)
{
    fn_80128E30(owner);
    return owner->link->pointerC;
}
