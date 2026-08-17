typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Runtime {
    u8 pad0[0xF4];
    u32 flags;
} Runtime;

extern Runtime* fn_80128E30(void*);

u16 fn_801290D0(void* owner)
{
    Runtime* runtime = fn_80128E30(owner);
    u32 flags = runtime != 0 ? runtime->flags : 0;
    return (u16)flags;
}
