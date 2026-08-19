typedef unsigned char u8;

typedef struct Link {
    u8 pad0[0xC];
    void* pointerC;
} Link;

typedef struct Owner {
    u8 pad0[0x160];
    Link* link;
} Owner;

#define FN_80128E30_RETURN void*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

void* fn_8012915C(Owner* owner)
{
    fn_80128E30(owner);
    return owner->link->pointerC;
}
