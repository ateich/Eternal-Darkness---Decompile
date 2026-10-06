typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

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
    s16 value04;
    u16 value06;
    u16 value08;
    u8 pad0A[10];
    Color color0;
    Color color1;
    u16 value1C;
    u16 value1E;
    u8 value20;
    u8 value21;
    u8 value22;
    u8 value23;
    u8 value24;
    u8 pad25[3];
    u8 value28;
    u8 value29;
    u8 pad2A[6];
    u16 value30;
    u8 pad32[14];
    float value40;
} Effect;

void fn_8018F76C(Effect* object)
{
    Color color0 = {230, 230, 255, 250};
    Color color1 = {120, 120, 155, 40};

    object->type = 21;
    object->value01 = 16;
    object->value04 = -1;
    object->value06 = 120;
    object->value08 = 5;
    object->value02 = 250;
    object->value03 = -2;
    object->color0 = color0;
    object->color1 = color1;
    object->value20 = 0;
    object->value22 = 180;
    object->value23 = 60;
    object->value30 = 512;
    object->value40 = 3.0f;
    object->value28 = 100;
    object->value29 = 6;
}
