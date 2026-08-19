typedef unsigned char u8;
typedef signed short s16;

typedef struct Vector {
    float x;
    float y;
    float z;
} Vector;

typedef struct ScreenPosition {
    int x;
    int y;
    int z;
} ScreenPosition;

extern void *fn_80201B9C();
extern void* fn_80204844(void*, int);
extern void* fn_8006D444(void);
extern int fn_8006D344(void*, int, int);
extern void* fn_8004918C(void);
extern unsigned int fn_801A7780(void);
extern void fn_801F6B6C(Vector*, ScreenPosition*, int, int);
extern void fn_801B0CA4(int, int);
extern s16 lbl_8031D3B8[10];
extern s16 lbl_8031D3CC[10];
extern u8 lbl_8064C91D;

void fn_800890F4(Vector* position)
{
    fn_80204844(fn_80201B9C(), 0x20);
    if (fn_8006D344(fn_8006D444(), 0x80, 0) != 0) {
        unsigned int flags;

        fn_8004918C();
        flags = fn_801A7780();
        if (position != 0) {
            if ((flags & 0x20) == 0) {
                Vector source;
                ScreenPosition screen;

                source.x = position->x;
                source.y = position->y;
                source.z = position->z;
                fn_801F6B6C(&source, &screen, 1, 0);
                lbl_8031D3B8[0] = (s16)(screen.x - 0x40);
                lbl_8031D3CC[0] = (s16)(screen.y - 0x40);
                lbl_8064C91D |= 2;
            }
            fn_801B0CA4(-1, 0x1B);
            lbl_8064C91D |= 1;
        } else if (flags & 0x10018) {
            fn_801B0CA4(-1, 0x1B);
            lbl_8064C91D |= 3;
        }
    }
}
