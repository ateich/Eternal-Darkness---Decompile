typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u8 lbl_802FC5BC[];

typedef struct Config {
    u8 field_00;
    u8 field_01;
    u8 pad_02;
    s8 field_03;
    u16 field_04;
    u8 pad_06[10];
    void* field_10;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 pad_19[3];
    u32 field_1c;
    u16 field_20;
} Config;

void fn_8019917C(Config* config)
{
    config->field_00 = 20;
    config->field_01 = 8;
    config->field_04 = 49;
    config->field_03 = -5;
    config->field_10 = *(void**)(lbl_802FC5BC + 0xc);
    config->field_14 = 20;
    config->field_15 = 2;
    config->field_16 = 30;
    config->field_17 = 180;
    config->field_18 = 120;
    config->field_1c = 0;
    config->field_20 = 0;
}
