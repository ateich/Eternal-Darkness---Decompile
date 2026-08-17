typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Runtime {
    u8 pad0[0xB4];
    u32 valueB4;
} Runtime;

u32 fn_80128C34(Runtime* runtime)
{
    return runtime->valueB4;
}
