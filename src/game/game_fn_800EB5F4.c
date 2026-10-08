typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

typedef union Color {
    u32 value;
    struct {
        u8 r;
        u8 g;
        u8 b;
        u8 a;
    } channel;
} Color;

extern u16 lbl_80325F48[5];
extern char lbl_80325F54[5][0x5E6];
extern u8 lbl_8064CB28[5];
extern u32 lbl_8064F880;
extern f32 lbl_8064F884;

extern void fn_801E3AA4(int);
extern void fn_801E5430(s16, s16);
extern u32 fn_801E3A34(Color*);
extern void fn_801E56AC(f32, const char*, ...);

void fn_800EB5F4(int type, int position)
{
    Color color;
    Color text_color;
    if (lbl_8064CB28[type] == 0) {
        return;
    }

    color.value = lbl_8064F880;
    if (lbl_80325F48[type] != 0) {
        lbl_80325F48[type]--;
    } else {
        color.channel.a = lbl_8064CB28[type];
        lbl_8064CB28[type]--;
    }

    fn_801E3AA4(0);
    fn_801E5430(10, 0x1A9 - (5 - position) * 15);
    text_color = color;
    fn_801E3A34(&text_color);
    fn_801E56AC(lbl_8064F884, lbl_80325F54[type]);
}
