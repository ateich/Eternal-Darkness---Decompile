typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct EffectDesc {
    u8 enabled;
    u8 count;
    u8 value2;
    s8 value3;
    u16 value4;
    u16 value6;
    u16 value8;
    u8 padA[6];
    u8 value10;
    u8 value11;
    u8 value12;
    u8 value13;
    u8 pad14[0x30];
    float scale;
    u8 value48;
    u8 value49;
} EffectDesc;

extern float lbl_80650D98;

void fn_801A4F74(EffectDesc* descriptor)
{
    descriptor->enabled = 1;
    descriptor->count = 0x20;
    {
        float scale = lbl_80650D98;
    descriptor->value2 = 0xff;
    descriptor->value3 = -5;
    descriptor->value4 = 5;
    descriptor->value6 = 0;
    descriptor->value8 = 0;
    descriptor->value10 = 0xff;
    descriptor->value11 = 0;
    descriptor->value12 = 0;
    descriptor->value13 = 0xff;
    descriptor->scale = scale;
    descriptor->value48 = 0;
    descriptor->value49 = 1;
    }
}
