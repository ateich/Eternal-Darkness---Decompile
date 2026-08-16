typedef struct Color { unsigned char r, g, b, a; } Color;

extern const Color lbl_8064F628;
extern const Color lbl_8064F62C;
extern const Color lbl_80651B28;
extern void fn_80201B54(void *);
extern void *fn_80201B8C(void *);
extern void *fn_80201890(void *);
extern void fn_8012C62C(void *, int, Color, Color, Color, int);

void fn_800E1AA8(void *object)
{
    Color source;
    volatile Color second;
    void *resource;

    source = lbl_8064F628;
    fn_80201B54(object);
    resource = fn_80201890(**(void ***)((unsigned char *)fn_80201B8C(object) + 0x78));
    second = lbl_80651B28;
    second.r = source.r;
    second.g = source.g;
    second.b = source.b;
    fn_8012C62C(resource, 15, source, lbl_8064F62C, second, 6);
}
