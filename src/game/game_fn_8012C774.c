typedef signed char s8;
typedef unsigned char u8;

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct ColorDelta {
    s8 r, g, b, a;
} ColorDelta;

#pragma use_lmw_stmw on

extern int fn_8012FA54(u8*, int);
extern void* fn_8012C62C(u8* state, int index, Color a, ColorDelta b, Color c, int flags);

void fn_8012C774(u8* state, Color a, ColorDelta b, Color c, int flags)
{
    int i;

    for (i = 0; i < 15; i++) {
        if (fn_8012FA54(state, i)) {
            fn_8012C62C(state, i, a, b, c, flags);
        }
    }
}
