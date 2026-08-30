typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Data801A743C {
    u8 pad0[0x78];
    u32 flags78;
} Data801A743C;

u32 fn_801A743C(Data801A743C* data, int enabled)
{
    u32 flags = data->flags78;
    u32 previous = flags & 1;

    data->flags78 = enabled ? flags | 1 : flags & ~1;
    return previous;
}
