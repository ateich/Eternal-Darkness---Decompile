typedef unsigned char u8;
typedef unsigned long u32;

typedef struct Color8 {
    u8 red, green, blue, alpha;
} Color8;

typedef struct ColorF {
    float red, green, blue, alpha;
} ColorF;

extern ColorF lbl_8063C608;
extern Color8 lbl_8064C384;

void fn_801F3528(Color8 color)
{
    lbl_8064C384 = color;
    lbl_8063C608.red = color.red;
    lbl_8063C608.green = color.green;
    lbl_8063C608.blue = color.blue;
    lbl_8063C608.alpha = color.alpha;
}
