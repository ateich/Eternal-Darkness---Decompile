typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

typedef struct Color {
    u8 r, g, b, a;
} Color;

extern void fn_801859FC(u8*, u8);

void fn_801857B4(u8* self)
{
    u8* object = self;
    Vector3 first = {0.0f, 0.0f, 0.0f};
    Vector3 second = {0.0f, 0.0f, 1.0f};
    Color value = {255, 255, 255, 255};

    object[0] = 31;
    object[1] = 255;
    *(u16*)(object + 4) = 82;
    *(u16*)(object + 6) = 130;
    *(u16*)(object + 8) = 5;
    object[2] = 250;
    *(signed char*)(object + 3) = -2;
    *(u16*)(object + 0x1C) = 10;
    *(u16*)(object + 0x1E) = 0x800;
    *(u16*)(object + 0x20) = 4;

    fn_801859FC(object, object[0]);

    object[0x14] = 20;
    object[0x15] = 5;
    object[0x18] = 0;
    *(Color*)(object + 0x78) = value;
    object[0x19] = 31;
    *(Vector3*)(object + 0x3C) = first;
    *(Vector3*)(object + 0x48) = first;
    *(Vector3*)(object + 0x30) = second;
}
