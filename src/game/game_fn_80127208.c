typedef unsigned char u8;

typedef struct Runtime {
    u8 pad0[0x100];
    u8 flags;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

int fn_80127208(void* owner)
{
    return fn_80128E30(owner)->flags & 1;
}
