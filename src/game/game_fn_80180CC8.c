typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Triple {
    u32 x;
    u32 y;
    u32 z;
} Triple;

void fn_80180CC8(u8* object, Triple* source)
{
    *(Triple*)(object + 0xD4) = *source;
}
