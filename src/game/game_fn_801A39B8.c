typedef unsigned long u32;

typedef struct Vec3Words {
    u32 x;
    u32 y;
    u32 z;
} Vec3Words;

void fn_801A39B8(void* object, Vec3Words* value)
{
    *(Vec3Words*)((char*)object + 0xB8) = *value;
}
