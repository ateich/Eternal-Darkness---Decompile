typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

typedef struct Config {
    u8 kind;
    u8 variant;
    u8 value;
    signed char delta;
    u16 field4;
    u16 field6;
    u16 field8;
    u8 padA[0xA];
    u16 field14;
    u16 field16;
    u32 field18;
} Config;

void fn_8019BCEC(Config* data)
{
    data->kind = 4;
    data->variant = 16;
    data->field4 = 47;
    data->value = 200;
    data->delta = -1;
    data->field6 = 7400;
    data->field8 = 3500;
    data->field14 = 4;
    data->field16 = 64;
    data->field18 = *(u32*)(lbl_802FC5BC + 0x18);
}
