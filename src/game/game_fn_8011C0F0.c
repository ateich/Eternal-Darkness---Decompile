typedef struct Entry {
    short x;
    short y;
    short width;
    short height;
} Entry;

typedef struct Quad {
    Entry entry[2];
} Quad;

extern const Quad lbl_8023A670;
extern int lbl_8064C2BC;

extern void fn_801A872C(int, int, int, int, int, int, int *);
extern void fn_801A8974(int, int, int, int, int, int);

void fn_8011C0F0(int index, unsigned char enabled)
{
    Quad quad = lbl_8023A670;
    int color;

    if (enabled != 0) {
        color = lbl_8064C2BC;
        fn_801A872C(quad.entry[index].x, quad.entry[index].y,
                    quad.entry[index].width, quad.entry[index].height,
                    -1, 3, &color);
    } else {
        fn_801A8974(quad.entry[index].x, quad.entry[index].y,
                    quad.entry[index].width, quad.entry[index].height,
                    -1, 3);
    }
}
