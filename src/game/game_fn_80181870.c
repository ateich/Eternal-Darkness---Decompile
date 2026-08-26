typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vector3Words {
    u32 x;
    u32 y;
    u32 z;
} Vector3Words;

typedef struct InitObject {
    u8 type;
    u8 count;
    u8 chance;
    s8 delta;
    s16 field_04;
    s16 field_06;
    s16 field_08;
    u8 pad_0A[0x0A];
    u8 field_14;
    u8 pad_15[5];
    s16 field_1A;
    s16 field_1C;
    u8 pad_1E[2];
    s16 field_20;
    u8 pad_22[2];
    s16 field_24;
    s16 field_26;
    s16 field_28;
    u8 pad_2A[0x1E];
    Vector3Words vector;
} InitObject;

extern const Vector3Words lbl_8023B028;

void fn_80181870(InitObject* object)
{
    Vector3Words vector = lbl_8023B028;

    object->type = 8;
    object->count = 16;
    object->field_04 = 52;
    object->field_06 = 5500;
    object->field_08 = 150;
    object->chance = 250;
    object->delta = -2;
    object->field_24 = 0;
    object->field_26 = 0;
    object->field_28 = -1;
    object->field_1C = 50;
    object->field_14 = 1;
    object->field_20 = 1;
    object->field_1A = 31;
    object->vector = vector;
}
