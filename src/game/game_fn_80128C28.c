typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Runtime {
    u8 pad0[0xB0];
    u32 valueB0;
    u32 valueB4;
} Runtime;

void fn_80128C28(Runtime* runtime, u32 valueB0, u32 valueB4)
{
    runtime->valueB0 = valueB0;
    runtime->valueB4 = valueB4;
}
