typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Triple {
    u32 x;
    u32 y;
    u32 z;
} Triple;

typedef struct Object {
    u8 first;
    u8 second;
    u8 third;
    s8 offset;
    u16 size;
    u16 field_06;
    u16 field_08;
    u8 pad_0A[6];
    u32 field_10;
    u8 field_14;
    u8 pad_15;
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 pad_19;
    u16 field_1A;
    u16 field_1C;
    u8 pad_1E[2];
    u16 field_20;
    u8 pad_22[2];
    u16 field_24;
    u16 field_26;
    u16 field_28;
    u8 pad_2A[2];
    float field_2C;
    u8 pad_30[0x18];
    Triple field_48;
} Object;

extern const Triple lbl_8023B018;
extern u8 lbl_802FC5BC[];
extern const float lbl_80650948;

void fn_80180D0C(Object* object)
{
    u16 size = 0x34;
    s8 offset = -10;
    u32 x = lbl_8023B018.x;
    u32 y = lbl_8023B018.y;
    u32 z = lbl_8023B018.z;
    Triple value;
    value.x = x;
    value.y = y;
    value.z = z;

    object->first = 0x10;
    object->second = 0x10;
    object->third = 0xFA;
    object->offset = offset;
    object->size = size;
    object->field_06 = 0xE1;
    object->field_08 = 0x64;
    object->field_10 = *(u32*)(lbl_802FC5BC + 0xC);
    object->field_24 = 0;
    object->field_26 = 0;
    object->field_28 = 0;
    object->field_1C = 0x12C;
    object->field_14 = 2;
    object->field_20 = 1;
    object->field_1A = 0x3F;
    object->field_16 = 4;
    object->field_2C = lbl_80650948;
    object->field_17 = 1;
    object->field_18 = 0x60;
    object->field_48 = value;
}
