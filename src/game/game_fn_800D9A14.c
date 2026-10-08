typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Actor {
    u8 pad0[0x84];
    u16 flags;
    u8 pad86[0x16];
    void *effects[4];
    Vec3 position;
    Vec3 raised_position;
} Actor;

extern u32 fn_801A7498(void *);
extern void *fn_80201814(u32);
extern Actor *fn_800A1D28(void *);
extern void fn_800A30F4(Actor *, int);
extern int fn_802045AC(void *, Vec3 *);
extern void fn_801CE744(u32, u32, const Vec3 *, u16, u32, u8, u32,
                       float, float);
extern u32 lbl_8064D18C;
extern const float lbl_8064F418;
extern const float lbl_8064F428;
extern const float lbl_8064F45C;

int fn_800D9A14(void *unused, void *context)
{
    void *object;
    Actor *actor;
    Vec3 position;

    (void)unused;
    object = fn_80201814(fn_801A7498(context));
    actor = fn_800A1D28(object);
    fn_800A30F4(actor, 0);
    fn_802045AC(object, &position);
    fn_801CE744(0x10904, lbl_8064D18C, &position, 0, 1, 0,
                (u32)&actor->effects[0], lbl_8064F418, lbl_8064F45C);
    actor->flags |= 4;
    actor->position = position;
    actor->raised_position = position;
    actor->raised_position.z += lbl_8064F428;
    return 1;
}
