typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Actor {
    u8 pad0[0x86];
    u16 mode;
    u8 pad88[0x1D8];
    u16 field260;
    u8 pad262[0x10];
    u16 field272;
    u8 pad274[0x10];
    u16 field284;
} Actor;

extern void *fn_80201BC8();
extern int fn_80201B54();
extern void fn_800A43E8(void *, void *);
extern void fn_8012C478(void *, int, int);
extern void fn_800DA308(void *, int);
extern void fn_800D8EC4(void *, void *, int);

void fn_800D8F38(Actor *actor, void *object, int kind)
{
    void *runtime = fn_80201BC8(object);
    void *value;

    switch (kind) {
    case 1:
        value = ((void *)fn_80201B54(object));
        fn_800A43E8(actor, value);
        fn_8012C478(runtime, 0, 0);
        break;
    case 2:
        fn_8012C478(runtime, 14, 0);
        break;
    }

    switch (actor->mode) {
    case 1:
        value = fn_80201BC8(object);
        actor->field272 = 3;
        actor->field260 = 360;
        fn_800DA308(value, 0);
        break;
    case 2:
        actor->field284 = 210;
        actor->field272 = 3;
        actor->field260 = 330;
        fn_8012C478(runtime, 0, 0);
        fn_800D8EC4(actor, runtime, 1);
        fn_800DA308(runtime, 14);
        break;
    case 3:
        break;
    }
}
