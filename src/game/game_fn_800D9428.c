typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Actor {
    u8 pad0[0x86];
    u16 mode;
    u8 pad88[0x10F];
    signed char notify;
    int state;
} Actor;

extern u32 lbl_8064F444;
extern u32 lbl_8064F448;
extern u32 lbl_8064F44C;
extern u32 lbl_8064F450;
extern void fn_8012DBE8(void *, int, u32 *);
extern void fn_800A1AF0(void *, int, void *, void *, u32 *, u32 *, u32 *, u16, u32);
extern void fn_800A3C84(void *, int, void *, void *);
extern void fn_800D91AC(void *, Actor *);
extern void fn_800A4C98(Actor *, void *);
extern void fn_800A4670(Actor *, void *, int);
extern void fn_800A2D78(Actor *);
extern void fn_800A4D04(Actor *);
extern void fn_800A4634(Actor *, void *);
extern void fn_8012FCB0(void *, int, int, int);
extern void fn_800D8EC4(Actor *, void *, int);

void fn_800D9428(Actor *actor, void *runtime, void *source, void *context)
{
    u16 flags = 0x100;
    u32 a0 = lbl_8064F450;
    u32 a1;
    u32 a2;
    u32 b0 = lbl_8064F444;
    u32 b1;
    u32 b2;

    if (source != 0) {
        flags |= 0x32;
        a1 = lbl_8064F450;
        a2 = lbl_8064F44C;
        b1 = lbl_8064F444;
        b2 = lbl_8064F44C;
    } else {
        flags |= 0x12;
        a1 = lbl_8064F444;
        a2 = lbl_8064F448;
        b1 = lbl_8064F450;
        b2 = lbl_8064F448;
    }
    if (actor->state != -1) {
        fn_8012DBE8(runtime, 15, &a1);
        fn_800A1AF0(runtime, actor->state, source, context, &a0, &a2, &a1,
                    flags, a1);
        b1 = a1;
    }
    if (actor->state != 1) {
        fn_800A1AF0(runtime, 1, source, context, &b0, &b2, &b1, flags, b1);
    }
    if (actor->notify != 0) {
        fn_800A3C84(runtime, actor->state, source, context);
    }
    if (source != 0) {
        fn_800D91AC(runtime, actor);
        fn_800A4C98(actor, runtime);
        fn_800A4670(actor, runtime, 16);
    } else {
        fn_800A2D78(actor);
        fn_800A4D04(actor);
        fn_800A4634(actor, runtime);
    }
    if (actor->mode == 2) {
        if (source != 0) {
            fn_8012FCB0(runtime, 14, 0, 0x400);
        } else {
            fn_8012FCB0(runtime, 14, 0x400, 0);
        }
        fn_800D8EC4(actor, runtime, 1);
    }
}
