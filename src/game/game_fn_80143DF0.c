typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct PoolSlot {
    u16 id;
    u8 flags;
    u8 count;
    s16 index;
    u8 pad[14];
} PoolSlot;

typedef struct PoolPart {
    u8 pad0[0x14];
    float dir[3];
    u8 pad20[0x50];
} PoolPart;

typedef struct PoolBox {
    s16 v[4][3];
} PoolBox;

typedef struct Pool {
    PoolSlot slots[12];
    PoolPart parts[12][7];
    PoolBox boxes[12][7];
} Pool;

extern Color lbl_802FC5BC[];
extern s16 lbl_802FC53C[];
extern Pool lbl_805B1310;
extern int lbl_8064D18C;

extern void fn_801ED468(int);
extern void fn_80226D28(int);
extern void fn_801ED118(void);
extern int fn_801EDA7C(s16* values, int context, int flags, void* state);
extern void fn_801ECF50(int);
extern void fn_80226C18(int, int);
extern void fn_801ECD74(Color* color);
extern void fn_80226AB4(int, int, int);
extern void fn_80144164(float x, float y, float z);
extern void fn_80144160(void);

void fn_80143DF0(void)
{
    Color base;
    Color faded;
    Color c1;
    Color c2;
    PoolPart (*parts)[7];
    PoolBox (*boxes)[7];
    PoolSlot* slot;
    int i;
    PoolBox* box;
    PoolPart* part;
    int j;
    Pool* pool;

    pool = &lbl_805B1310;
    base = lbl_802FC5BC[11];
    fn_801ED468(0x1b);
    fn_80226D28(0);
    fn_801ED118();
    fn_801EDA7C(lbl_802FC53C, 0, 0x2bf, 0);
    fn_801ECF50(4);
    fn_80226C18(0x12, 0);
    base.a = 0x40;
    faded = base;
    fn_801ECD74(&faded);

    for (i = 0; i < 12; i++) {
        slot = &pool->slots[i];
        if (!(slot->flags & 1) || slot->id != lbl_8064D18C) {
            continue;
        }
        boxes = pool->boxes;
        parts = pool->parts;
        for (j = 0; j < slot->count; j++) {
            c1 = base;
            box = &boxes[slot->index][j];
            part = &parts[slot->index][j];
            fn_801ECD74(&c1);
            fn_80226AB4(0x80, 3, 4);
            fn_80144164(box->v[0][0], box->v[0][1], box->v[0][2]);
            fn_80144164(box->v[1][0], box->v[1][1], box->v[1][2]);
            fn_80144164(box->v[2][0], box->v[2][1], box->v[2][2]);
            fn_80144164(box->v[3][0], box->v[3][1], box->v[3][2]);
            fn_80144160();
            c2 = lbl_802FC5BC[3];
            fn_801ECD74(&c2);
            fn_80226AB4(0xa8, 3, 2);
            fn_80144164(box->v[0][0], box->v[0][1], box->v[0][2]);
            fn_80144164(box->v[0][0] + 100.0f * part->dir[0],
                        box->v[0][1] + 100.0f * part->dir[1],
                        box->v[0][2] + 100.0f * part->dir[2]);
            fn_80144160();
        }
    }
}
