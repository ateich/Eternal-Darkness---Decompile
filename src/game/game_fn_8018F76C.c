typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color {
    u32 value;
} Color;

extern const Color lbl_80650AE0;
extern const Color lbl_80650AE4;
extern const float lbl_80650AE8;

/* Keep aggregate arguments local to this translation unit. */
static inline void initialize_descriptor(u8* desc, u8 field_00, u8 field_01,
    s16 field_04, u16 field_06, u16 field_08, u8 field_02, s8 field_03,
    Color color0, Color color1, u8 field_20, u8 field_22, u8 field_23,
    u16 field_30, float field_40, u8 field_28, u8 field_29)
{
    desc[0] = field_00;
    desc[1] = field_01;
    *(s16*)(desc + 4) = field_04;
    *(u16*)(desc + 6) = field_06;
    *(u16*)(desc + 8) = field_08;
    desc[2] = field_02;
    ((s8*)desc)[3] = field_03;
    *(Color*)(desc + 0x14) = color0;
    *(Color*)(desc + 0x18) = color1;
    desc[0x20] = field_20;
    desc[0x22] = field_22;
    desc[0x23] = field_23;
    *(u16*)(desc + 0x30) = field_30;
    *(float*)(desc + 0x40) = field_40;
    desc[0x28] = field_28;
    desc[0x29] = field_29;
}

void fn_8018F76C(u8* desc)
{
    initialize_descriptor(desc, 21, 16, -1, 120, 5, 250, -2,
        lbl_80650AE0, lbl_80650AE4, 0, 180, 60, 512, lbl_80650AE8, 100, 6);
}
