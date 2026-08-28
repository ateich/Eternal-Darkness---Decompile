typedef unsigned int u32;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

void fn_801911D8(unsigned char* data, const Vec3* value)
{
    *(Vec3*)(data + 0xB8) = *value;
}
