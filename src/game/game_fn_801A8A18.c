typedef unsigned char u8;
typedef unsigned long u32;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

u32 fn_801A8A18(const Color* current, const Color* target, const Color* step)
{
    Color result;
    int value;
    int red;
    int green;
    int blue;

    if (target->r < current->r) {
        value = current->r - step->r;
        if (target->r > value) value = target->r;
        red = value;
    } else {
        value = current->r + step->r;
        if (target->r < value) value = target->r;
        red = value;
    }

    if (target->g < current->g) {
        value = current->g - step->g;
        if (target->g > value) value = target->g;
        green = value;
    } else {
        value = current->g + step->g;
        if (target->g < value) value = target->g;
        green = value;
    }

    if (target->b < current->b) {
        value = current->b - step->b;
        if (target->b > value) value = target->b;
        blue = value;
    } else {
        value = current->b + step->b;
        if (target->b < value) value = target->b;
        blue = value;
    }

    if (target->a < current->a) {
        value = current->a - step->a;
        if (target->a > value) value = target->a;
    } else {
        value = current->a + step->a;
        if (target->a < value) value = target->a;
    }
    result.r = red;
    result.g = green;
    result.b = blue;
    result.a = value;

    return *(u32*)&result;
}
