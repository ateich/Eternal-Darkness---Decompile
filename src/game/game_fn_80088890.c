typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Context {
    u8 pad[8];
    u16 counter;
} Context;

typedef struct Owner {
    u8 pad[0x159];
    u8 active;
    u8 pad15A[6];
    u16 value;
} Owner;

typedef struct Work {
    u8 bytes[0xC4];
    Owner* owner;
} Work;

extern void *fn_8006ED3C();
extern void fn_8006BEE4(Context*, void (*)(void));
extern void fn_8006DEF8(Work*, int, void*, void*, int);
extern void fn_8006EB60(void);
extern void fn_80087D64(void);
extern void fn_80087EC4(void);
extern void fn_80088060(void);
extern void fn_80088298(void);
extern void fn_800FD40C(void*, const void*);
extern const u8 lbl_802450A8[];
extern int lbl_8064C8C4;
extern u8 lbl_8064C91C;
extern u8 lbl_8064C91D;

void fn_80088890(Work* work)
{
    int index;
    Context* context = fn_8006ED3C(work, 7, &index);

    context->counter = 0;
    fn_8006BEE4(context, fn_8006EB60);
    work->owner->active = 0;
    work->owner->value = 0;
    work->bytes[index * 0x2C + 0x6A] = 0;
    work->bytes[index * 0x2C + 0x6B] = 0;
    work->bytes[index * 0x2C + 0x68] = 4;
    fn_8006DEF8(work, 7, fn_80087D64, work, 100);
    work->bytes[index * 0x2C + 0x68] = 0;
    fn_8006DEF8(work, 7, fn_80087EC4, work, 1);
    work->bytes[index * 0x2C + 0x68] = 1;
    fn_8006DEF8(work, 7, fn_80088060, work, 50);
    work->bytes[index * 0x2C + 0x68] = 2;
    fn_8006DEF8(work, 7, fn_80088298, work, 50);
    work->bytes[index * 0x2C + 0x68] = 0;
    fn_800FD40C(work->bytes + 0x18, lbl_802450A8);
    lbl_8064C8C4 = 0;
    lbl_8064C91C = 1;
    lbl_8064C91D = 0;
}
