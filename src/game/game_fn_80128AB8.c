typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    u8 pad0[0x254];
    u32 flags;
} Owner;

typedef struct Runtime {
    u8 pad0[0xF4];
    u32 flags;
    u8 padF8[6];
    u16 value;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS Owner*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

int fn_80128AB8(Owner* owner, u32 value)
{
    Runtime* runtime;
    u16 narrowed = value;

    owner->flags |= 4;
    if (narrowed != 0) {
        runtime = fn_80128E30(owner);
        if (runtime != 0) {
            runtime->value = narrowed;
            runtime->flags |= 8;
        }
    }
    return 1;
}
