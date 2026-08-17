typedef unsigned char u8;

typedef struct Link {
    u8 pad0[4];
    void* pointer;
} Link;

typedef struct Owner {
    u8 pad0[0x160];
    Link* link;
} Owner;

extern void fn_801261F4(void);

void* fn_80128F40(Owner* owner)
{
    fn_801261F4();
    return owner->link->pointer;
}
