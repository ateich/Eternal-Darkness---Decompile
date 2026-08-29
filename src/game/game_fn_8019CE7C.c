typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Vec3 {
    u32 value[3];
} Vec3;

void fn_8019CE7C(u8* object, Vec3* first, Vec3* second, Vec3* third)
{
    *(Vec3*)(object + 0xC4) = *first;
    *(Vec3*)(object + 0xF4) = *third;
    *(Vec3*)(object + 0xD0) = second[0];
    *(Vec3*)(object + 0xDC) = second[1];
    *(Vec3*)(object + 0xE8) = second[2];
}
