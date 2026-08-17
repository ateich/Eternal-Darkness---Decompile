typedef unsigned char u8;

typedef struct Runtime {
    u8 pad0[0x100];
    u8 flags;
} Runtime;

extern Runtime* fn_80128E30(void*);

int fn_80127208(void* owner)
{
    return fn_80128E30(owner)->flags & 1;
}
