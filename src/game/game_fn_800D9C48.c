typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

typedef struct Actor {
    u8 pad0[0x284];
    u16 timer;
} Actor;

extern void *fn_801A717C(void);
extern int fn_80201B54(void *);
extern int fn_801A74B8(void *);
extern void fn_801A74A0(void *, int);
extern void fn_801A7538(void *, int);
extern void fn_801A7518(void *, int);
extern void fn_801A7588(void *, int);
extern void fn_801D38BC(int, int *, s16 *);
extern int fn_800C8568(void *, void *, void *, s16, int, int, int *);
extern void fn_801A7228(void *);
extern void fn_800A33A8(void *);
extern void fn_800A32B8(void *);
extern Actor *fn_800A1D28(void *);
extern void fn_800A37CC(int, int, void *);

void fn_800D9C48(void *object, void *position)
{
    int effect = 0;
    void *resource;
    int owner = 0;
    int value = 0;
    resource = fn_801A717C();

    if (resource != 0) {
        int parameter;
        int result;
        s16 height;

        owner = fn_80201B54(object);
        value = fn_801A74B8(resource);
        fn_801A74A0(resource, owner);
        fn_801A7538(resource, 5);
        fn_801A7518(resource, 5);
        fn_801A7588(resource, 0x8000);
        fn_801D38BC(3, &parameter, &height);
        result = parameter;
        effect = fn_800C8568(object, resource, position, height, 0xBE, 0x3B,
                              &result);
        fn_801A7228(resource);
        resource = 0;
    }
    fn_800A33A8(position);
    fn_800A32B8(position);
    if (effect != 0) {
        Actor *actor = fn_800A1D28(object);
        actor->timer = 0xD2;
        fn_800A37CC(owner, value, resource);
    }
}
