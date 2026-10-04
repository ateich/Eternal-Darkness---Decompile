typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Triple {
    u32 x;
    u32 y;
    u32 z;
} Triple;

typedef struct Effect {
    u8 type;
    u8 value01;
    u8 value02;
    s8 value03;
    u16 value04;
    u16 value06;
    u16 value08;
    u8 pad0A[6];
    u32 value10;
    u8 value14;
    u8 pad15;
    u8 value16;
    u8 value17;
    u8 value18;
    u8 pad19;
    u16 value1A;
    u16 value1C;
    u8 pad1E[2];
    u16 value20;
    u8 pad22[2];
    u16 value24;
    u16 value26;
    u16 value28;
    u8 pad2A[2];
    float value2C;
    u8 pad30[0x18];
    Triple value48;
} Effect;

extern Triple lbl_8023B018;
extern u8 lbl_802FC5BC[];
extern const float lbl_80650948;

void fn_80180D0C(Effect* object)
{
    u16 size = 0x34;
    s8 offset = -10;
    Triple value = lbl_8023B018;

    object->type = 0x10;
    object->value01 = 0x10;
    object->value02 = 0xFA;
    object->value03 = offset;
    object->value04 = size;
    object->value06 = 0xE1;
    object->value08 = 0x64;
    object->value10 = *(u32*)(lbl_802FC5BC + 0xC);
    object->value24 = 0;
    object->value26 = 0;
    object->value28 = 0;
    object->value1C = 0x12C;
    object->value14 = 2;
    object->value20 = 1;
    object->value1A = 0x3F;
    object->value16 = 4;
    object->value2C = lbl_80650948;
    object->value17 = 1;
    object->value18 = 0x60;
    object->value48 = value;
}
