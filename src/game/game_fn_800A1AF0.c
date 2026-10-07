typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color {
    u8 r, g, b, a;
} Color;

extern void* fn_8012C62C(u8*, int, void*, s8*, void*, int);
extern void fn_8012F58C(void*, u32, u32, u16, u16, u16);
extern void fn_8012C278(u8*, int);

void fn_800A1AF0(void* object, int index, int active, int copy_values,
                 Color first_in, Color second_in, Color third_in, int mode)
{
    Color first;
    Color second;
    Color third;

    if (copy_values) {
        second = second_in;
        third = third_in;
        first = first_in;
        fn_8012C62C(object, index, &first, (s8*)&second, &third, mode);
        if (!active) {
            fn_8012F58C(object, index, 0, 0, 0, 2);
        }
    } else {
        fn_8012C278(object, index);
    }
}
