typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Runtime {
    u8 pad0[0xFA];
    u16 valueFA;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

u16 fn_801291CC(void* owner)
{
    return fn_80128E30(owner)->valueFA;
}
