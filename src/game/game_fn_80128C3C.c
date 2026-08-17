typedef unsigned char u8;

typedef struct Runtime {
    u8 pad0[0xBC];
    float valueBC;
} Runtime;

void fn_80128C3C(Runtime* runtime, float value)
{
    runtime->valueBC = value;
}
