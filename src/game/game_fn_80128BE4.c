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
extern float lbl_806501A8;

void fn_80128BE4(void* owner)
{
    Runtime* runtime = fn_80128E30(owner);
    if (runtime != 0) {
        u32 flags = runtime->flags;
        float zero = lbl_806501A8;
        runtime->flags = flags & 0xFFFFE7FF;
        runtime->vector.x = zero;
        runtime->vector.y = zero;
        runtime->vector.z = zero;
    }
}
