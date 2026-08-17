typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Runtime {
    u8 pad0[0xA8];
    u32 valueA8;
    u32 valueAC;
} Runtime;

void fn_80128C44(Runtime* runtime, u32 valueA8, u32 valueAC)
{
    runtime->valueA8 = valueA8;
    runtime->valueAC = valueAC;
}
