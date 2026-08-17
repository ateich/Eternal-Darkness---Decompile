typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Runtime {
    u8 pad0[0xFA];
    u16 valueFA;
} Runtime;

extern Runtime* fn_80128E30(void*);

u16 fn_801291CC(void* owner)
{
    return fn_80128E30(owner)->valueFA;
}
