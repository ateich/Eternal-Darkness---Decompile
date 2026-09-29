typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* A color is passed both as a packed word and as four channel bytes. */
typedef union PackedColor {
    u32 value;
    u8 channels[4];
} PackedColor;

typedef struct ColorTriplet {
    PackedColor option_a;
    PackedColor active;
    PackedColor option_b;
} ColorTriplet;

typedef struct Initializers {
    ColorTriplet first;
    ColorTriplet second;
    PackedColor selected;
} Initializers;

typedef struct CallColors {
    PackedColor third;
    PackedColor second;
    PackedColor first;
} CallColors;

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
extern u16 fn_8012DBE8(u8 *, u32, u8 *);
extern void fn_800A1AF0(void *, int, int, int, volatile u32 *,
                       volatile u32 *, volatile u32 *, int);
extern void fn_800A3C84(void *, int, int, int);
extern void fn_800D91AC(void *, Actor *);
extern void fn_800A4C98(Actor *, void *);
extern void fn_800A4670(Actor *, void *, int);
extern void fn_800A2D78(Actor *);
extern void fn_800A4D04(Actor *);
extern void fn_800A4634(Actor *, void *);
extern u16 fn_8012FCB0(void *, int, u16, u16);
extern void fn_800D8EC4(Actor *, void *, int);

/* NonMatching: packed-color copies preserve retail storage without volatile
 * locals; persistent register allocation and call scheduling still differ. */
void fn_800D9428(Actor *actor, void *runtime, int source, int context)
{
    u16 flags = 0x100;
    int state;
    Initializers initializers;
    /* Four-byte aggregate copies retain the separate call arguments. */
    CallColors first;
    CallColors second;
    /* Retail preserves one otherwise-dead copy at the outgoing-area edge. */
    PackedColor extra;

    initializers.second.option_b.value = lbl_8064F444;
    initializers.second.option_a.value = lbl_8064F448;
    initializers.first.option_b.value = lbl_8064F44C;
    initializers.first.option_a.value = lbl_8064F450;

    if (source != 0) {
        flags |= 0x32;
        initializers.first.active = initializers.first.option_a;
        initializers.selected = initializers.second.option_b;
        initializers.second.active = initializers.first.option_b;
    } else {
        flags |= 0x12;
        initializers.first.active = initializers.second.option_b;
        initializers.selected = initializers.first.option_a;
        initializers.second.active = initializers.second.option_a;
    }
    if (actor->state != -1) {
        fn_8012DBE8((u8 *)runtime, 15, initializers.first.active.channels);
        first.third = initializers.first.active;
        first.second = initializers.second.active;
        first.first = initializers.first.active;
        extra = initializers.first.active;
        state = actor->state;
        initializers.selected = initializers.first.active;
        fn_800A1AF0(runtime, state, source, context,
                    &first.first.value, &first.second.value,
                    &first.third.value, flags);
    }
    if (actor->state != 1) {
        second.third = initializers.selected;
        second.second = initializers.second.active;
        second.first = initializers.first.active;
        fn_800A1AF0(runtime, 1, source, context,
                    &second.first.value, &second.second.value,
                    &second.third.value, flags);
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
