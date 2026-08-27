typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Resource {
    u8 pad0[8];
    u16 value8;
    u8 padA[14];
    void *value18;
} Resource;

extern u8 lbl_803108B8[];
extern void *lbl_8064C8C0;
extern s32 lbl_8064C8C4;
extern s32 lbl_8064C8C8;
extern s32 lbl_8064C8CC;
extern void *lbl_8064C8D0;
extern void *lbl_8064C8D4;
extern s32 lbl_8064C914;

extern void *memset(void *dest, s32 value, unsigned long size);
extern Resource *fn_8006D1DC(s32 kind);
extern void fn_8006B364(void *state);
extern void fn_8006B40C(void);
extern void fn_800AE2D4(s32 mode);
extern void fn_80088F08(s32 first, s32 second);
extern void fn_800891F4(s32 value);
extern unsigned int fn_800FBFB0(void);
#define fn_800FBFB0() ((int)fn_800FBFB0())

void fn_8006B21C(s32 mode)
{
    u8 *base = lbl_803108B8;
    Resource *resource;

    lbl_8064C8D4 = base;
    lbl_8064C8D0 = base + 0x630;
    switch (mode) {
    case 1:
        base[0x65A] = 0;
        base[0x65C] = 5;
        *(u16 *)(base + 0x65E) = 0;
        base[0x65D] = 1;
        resource = fn_8006D1DC(0x25);
        if (resource != 0) {
            resource->value8 = 0;
            resource->value18 = 0;
        }
        fn_8006D1DC(0xC);
        break;
    default:
        memset(base + 0x654, 0, 0x164);
        *(void **)(base + 0x7B0) = base + 0x7B8;
        fn_8006B364(base + 0x654);
        break;
    }
    fn_8006B40C();
    memset(base + 0x7B8, 0, 0x1788);
    memset(base + 0x1F40, 0, 0x80);
    memset(base + 0x1FC0, 0, 0x10);
    fn_800AE2D4(mode);
    lbl_8064C8C8 = 0;
    lbl_8064C8C4 = 0;
    lbl_8064C8CC = 0x10000;
    fn_80088F08(0, -1);
    fn_800891F4(-15);
    lbl_8064C914 = 0;
    if ((fn_800FBFB0() & 0x7F) > 0x40) {
        fn_800891F4(15);
    }
    lbl_8064C8C0 = 0;
}
