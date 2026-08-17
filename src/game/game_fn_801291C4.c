typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Runtime {
    u8 pad0[0xFA];
    u16 valueFA;
} Runtime;

void fn_801291C4(Runtime* runtime, u16 value)
{
    runtime->valueFA = value;
}
