typedef unsigned char u8;

typedef struct Actor {
    u8 pad0[0xAC];
    u8 position[12];
} Actor;

extern Actor *fn_800A1D28(void *);
extern void fn_800A33A8(void *);
extern void fn_801AC9F4(int, int, void *, int);
extern void fn_800D9C48(void *, void *);

int fn_800D9BE0(void *unused, void *object)
{
    Actor *actor = fn_800A1D28(object);
    (void)unused;
    fn_800A33A8(actor->position);
    fn_801AC9F4(0x25B, 100, actor->position, 2);
    fn_800D9C48(object, actor->position);
    return 1;
}
