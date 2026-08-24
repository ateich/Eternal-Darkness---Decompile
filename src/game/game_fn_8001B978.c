typedef unsigned char u8;
typedef int s32;

typedef struct Color {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} Color;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801ECBBC(Color*);
extern char lbl_8023BEF8[];

s32 fn_8001B978(void* arg)
{
    Color values;
    Color color;

    if (fn_8016A598(arg) != 4) {
        fn_80163BB4(arg, lbl_8023BEF8, 4, fn_8016A598(arg));
        return 0;
    }

    values.red = (u8)fn_8016A694(arg, 1);
    values.green = (u8)fn_8016A694(arg, 2);
    values.blue = (u8)fn_8016A694(arg, 3);
    values.alpha = (u8)fn_8016A694(arg, 4);
    color = values;
    fn_801ECBBC(&color);
    return 0;
}
