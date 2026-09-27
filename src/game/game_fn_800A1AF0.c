typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct ColorDelta {
    s8 r, g, b, a;
} ColorDelta;

extern void* fn_8012C62C(u8* state, int index, Color a, ColorDelta b, Color c, u16 flags);
extern void fn_8012F58C(void* object, u32 group, u32 index, u16 first, u16 second, u16 flags);
extern void fn_8012C278(u8* owner, int index);

void fn_800A1AF0(void* object, int index, int active, int copy_values,
                 Color first, ColorDelta second, Color third, u16 mode)
{
    if (copy_values) {
        fn_8012C62C(object, index, first, second, third, mode);
        if (!active) {
            fn_8012F58C(object, index, 0, 0, 0, 2);
        }
    } else {
        fn_8012C278(object, index);
    }
}
