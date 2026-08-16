typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Runtime800A30CC {
    u8 pad000[0x26E];
    u16 value;
} Runtime800A30CC;

typedef struct Context800A30CC {
    u8 pad00[0x64];
    Runtime800A30CC* runtime;
} Context800A30CC;

extern Context800A30CC*fn_80201B8C();

u16 fn_800A30CC(void* object)
{
    return fn_80201B8C(object)->runtime->value;
}
