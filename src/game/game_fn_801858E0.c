typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct Effect {
    u8 type;
    u8 value01;
    u8 value02;
    signed char value03;
    u16 value04;
    u16 value06;
    u16 value08;
    u8 pad0A[10];
    u8 value14;
    u8 value15;
    u8 pad16[2];
    u8 value18;
    u8 value19;
    u8 pad1A[2];
    u16 value1C;
    u16 value1E;
    u16 value20;
    u8 pad22[0xE];
    Vector3 second;
    Vector3 first;
    Vector3 first_copy;
    u8 pad54[0x24];
    Color value78;
} Effect;

extern void fn_801859FC(Effect*, u8);

void fn_801858E0(Effect* self)
{
    Vector3 first = {0.0f, 0.0f, 0.0f};
    Vector3 second = {0.0f, 0.0f, 1.0f};
    Color value = {255, 255, 255, 255};

    self->type = 31;
    self->value01 = 64;
    self->value04 = 5;
    self->value06 = 130;
    self->value08 = 5;
    self->value02 = 250;
    self->value03 = -2;
    self->value1C = 100;
    self->value1E = 0x800;
    self->value20 = 4;
    fn_801859FC(self, self->type);
    self->value14 = 20;
    self->value15 = 3;
    self->value78 = value;
    self->value18 = 20;
    self->value19 = 31;
    self->first = first;
    self->first_copy = first;
    self->second = second;
}
