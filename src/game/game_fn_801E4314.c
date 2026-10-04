typedef signed short s16;
typedef unsigned int u32;

typedef struct Color {
    u32 value;
} Color;

extern Color lbl_80651270;
extern Color lbl_80651274;
extern int lbl_8064D570;
extern int lbl_8064D580;
extern int lbl_806333C8[];
extern int lbl_8064C31C;
extern int lbl_8064C320;

extern void fn_801ECF50(int);
extern void fn_801ED3F4(int);
extern void fn_801A852C(Color, int, int, u32);
extern void fn_80226AB4(int, int, int);
extern void fn_801E4198(s16, s16, s16);
extern void fn_801E4188(void);
extern void fn_801E46E8(s16, s16);
extern void fn_801E46F8(int);

static inline void draw_vertex(s16 x, s16 y, s16 u, s16 v)
{
    fn_801E4198(x, y, -1);
    fn_801E46F8(0);
    fn_801E46E8(u, v);
}

void fn_801E4314(int x, int y, int width, s16 height, float scale, int dark)
{
    float scaled_depth = 8.0f * scale;
    s16 sx = x;
    int sy = (s16)y;
    s16 sw = width;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    s16 cx;
    s16 cy;
    int raw_depth;
    s16 depth;
    Color color;
    Color dark_color;
    Color light_color;
    Color* color_copy;
    s16 left_x;
    s16 top_y;
    s16 right_x;
    s16 bottom_y;

    cx = (sw >> 1) + sx;
    cy = (height >> 1) + sy;
    raw_depth = (int)scaled_depth;
    depth = raw_depth;
    left = ((sw >> 1) + depth) * 512 / 17;
    top = ((height >> 1) + depth) * 512 / 17;
    right = (17 - ((height >> 1) + depth)) * 512 / 17;
    bottom = (17 - ((sw >> 1) + depth)) * 512 / 17;

    if (dark) {
        dark_color = lbl_80651270;
        color_copy = &dark_color;
    } else {
        light_color = lbl_80651274;
        color_copy = &light_color;
    }
    color = *color_copy;
    y -= raw_depth;
    x -= raw_depth;

    fn_801ECF50(9);
    fn_801ED3F4(lbl_8064D570);
    fn_801A852C(color, 0, 0, 0x80000000);
    lbl_8064C31C = -1;
    lbl_8064C320 = -1;
    fn_80226AB4(0x80, 5, 0x10);

    left_x = x;
    draw_vertex(left_x, cy, 30, right);
    top_y = y;
    draw_vertex(left_x, top_y, 30, 481);
    draw_vertex(cx, top_y, left, 481);
    draw_vertex(cx, cy, left, right);
    draw_vertex(cx, cy, top, bottom);
    draw_vertex(cx, top_y, 30, bottom);

    right_x = sx + depth + sw;
    draw_vertex(right_x, top_y, 30, 481);
    draw_vertex(right_x, cy, top, 481);
    bottom_y = sy + depth + height;
    draw_vertex(cx, bottom_y, left, 481);
    draw_vertex(cx, cy, left, right);
    draw_vertex(right_x, cy, 30, right);
    draw_vertex(right_x, bottom_y, 30, 481);
    draw_vertex(left_x, bottom_y, 30, 481);
    draw_vertex(left_x, cy, top, 481);
    draw_vertex(cx, cy, top, bottom);
    draw_vertex(cx, bottom_y, 30, bottom);

    fn_801E4188();
    fn_801ED3F4(lbl_806333C8[lbl_8064D580]);
}
