typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef union Color {
    u32 value;
    u8 channels[4];
} Color;

typedef struct LinkOwner LinkOwner;
typedef struct Object {
    void *primary;
    u8 *secondary;
} Object;

extern void *fn_80201C24(LinkOwner *context);
extern u8 fn_80157AB8(Object *object);
extern u16 fn_8012DBE8(u8 *object, u32 index, u8 *color);
extern void *fn_8012C62C(u8 *object, int index, void *blue, s8 *green,
                         void *red, u16 flags);
extern void fn_8020104C(int type, int source, int target, int argument,
                        float delay);

extern u32 lbl_8064F840;
extern u32 lbl_80651B68;

void fn_800E9E44(LinkOwner *context, u8 *object, int id)
{
    Color color;
    u32 blue;
    u32 green;
    u32 red;
    u16 flags = 4;

    if (fn_80157AB8((Object *)fn_80201C24(context)) != 0) {
        flags |= 0x12;
    }

    fn_8012DBE8(object, 15, (u8 *)&color);
    red = lbl_80651B68;
    green = lbl_8064F840;
    blue = color.value;
    fn_8012C62C(object, 15, &blue, (s8 *)&green, &red, flags);
    fn_8020104C(0x39, id, id, 0, (float)color.channels[3]);
}
