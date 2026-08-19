typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Runtime {
    u8 pad0[0xE4];
    Vec3 vector;
    u8 padF0[4];
    u32 flags;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

void fn_80128B34(void* owner, Vec3* vector)
{
    Runtime* runtime = fn_80128E30(owner);
    if (runtime != 0) {
        runtime->flags |= 0x800;
        runtime->vector = *vector;
    }
}
