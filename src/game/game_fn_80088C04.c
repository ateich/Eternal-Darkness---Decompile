typedef unsigned char u8;
typedef signed short s16;

typedef struct Context {
    u8 pad[8];
    s16 counter;
} Context;

typedef struct Work {
    u8 bytes[0xC4];
} Work;

extern Context* fn_8006ED3C(Work*, int, int*);
extern void fn_8006BEE4(Context*, void (*)(void));
extern void fn_8006EB60(void);
extern void fn_8006DEF8(Work*, int, void*, void*, int);
extern int fn_80088B04(void*);
extern void fn_800FD40C(void*, const void*);
extern const u8 lbl_802450C0[];

void fn_80088C04(Work* work)
{
    int index;
    Context* context = fn_8006ED3C(work, 8, &index);
    int i;

    context->counter = 0;
    fn_8006BEE4(context, fn_8006EB60);
    work->bytes[index * 0x2C + 0x6A] = 0;
    work->bytes[index * 0x2C + 0x6B] = 0;
    work->bytes[index * 0x2C + 0x68] = 4;
    fn_8006DEF8(work, 8, fn_80088B04, work, 200);
    for (i = 0; i < 3; i++) {
        work->bytes[index * 0x2C + 0x68] = i;
        fn_8006DEF8(work, 8, 0, 0, 1);
    }
    work->bytes[index * 0x2C + 0x68] = 0;
    fn_800FD40C(work->bytes + 0x18, lbl_802450C0);
}
