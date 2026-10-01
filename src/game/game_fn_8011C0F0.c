typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    short x;
    short y;
    short width;
    short height;
} Entry;

typedef struct Quad {
    Entry entry[2];
} Quad;

typedef struct Box {
    u32 color;
    Quad quad;
} Box;

extern Quad lbl_8023A670;
extern u32 lbl_8064C2BC;

extern void fn_801A872C(int, int, int, int, int, int, u32*);
extern void fn_801A8974(int, int, int, int, int, int);

void fn_8011C0F0(int index, u8 enabled)
{
    Box box;

    box.quad = lbl_8023A670;
    if (enabled != 0) {
        int x = box.quad.entry[index].x;
        int y = box.quad.entry[index].y;
        int width = box.quad.entry[index].width;
        int height = box.quad.entry[index].height;

        box.color = lbl_8064C2BC;
        fn_801A872C(x, y, width, height, -1, 3, &box.color);
    } else {
        fn_801A8974(box.quad.entry[index].x, box.quad.entry[index].y,
                    box.quad.entry[index].width, box.quad.entry[index].height, -1, 3);
    }
}
