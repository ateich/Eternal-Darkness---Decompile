#pragma use_lmw_stmw on

typedef void (*Callback)(void);

typedef struct Actor {
    Callback *callbacks;
    unsigned char pad_004[0x260];
    const void *descriptor;
    unsigned char pad_268[4];
    unsigned short field_26c;
    unsigned short field_26e;
    unsigned short field_270;
    unsigned short field_272;
    unsigned char pad_274[0x10];
    unsigned short field_284;
} Actor;

extern char lbl_80248B78[];
extern void fn_800D6910(void);
extern void fn_800D6A20(void);
extern void fn_800D6A28(void);
extern void fn_800D6A3C(void);
extern void fn_800D8644(void);
extern void fn_800D8744(void);
extern void fn_800D877C(void);
extern void fn_800D87B4(void);
extern void fn_800D87EC(void);
extern void fn_800D9428(void);
extern void fn_800D88DC(void);
extern void fn_800D8AD8(void);
extern void fn_800D8B6C(void);
extern void fn_800D8B74(void);
extern void fn_800D8C3C(void);
extern void fn_800D8CB8(void);
extern void fn_800D8E30(void);
extern void fn_800D8F38(void);

void fn_800D67A4(Actor *actor)
{
    actor->descriptor = lbl_80248B78;
    actor->field_26c = 50;
    actor->field_26e = 1800;
    actor->field_270 = 7000;
    actor->field_272 = 3;
    ((unsigned char *)actor)[0x25d] = 0;
    actor->field_284 = 0;

    actor->callbacks[0] = fn_800D6910;
    actor->callbacks[1] = fn_800D6A20;
    actor->callbacks[2] = fn_800D6A28;
    actor->callbacks[3] = fn_800D6A3C;
    actor->callbacks[4] = fn_800D8644;
    actor->callbacks[5] = fn_800D8744;
    actor->callbacks[6] = fn_800D877C;
    actor->callbacks[7] = fn_800D87B4;
    actor->callbacks[8] = fn_800D87EC;
    actor->callbacks[10] = fn_800D9428;
    actor->callbacks[11] = fn_800D88DC;
    actor->callbacks[12] = fn_800D8AD8;
    actor->callbacks[13] = fn_800D8B6C;
    actor->callbacks[14] = fn_800D8B74;
    actor->callbacks[15] = fn_800D8C3C;
    actor->callbacks[16] = fn_800D8CB8;
    actor->callbacks[17] = fn_800D8E30;
    actor->callbacks[18] = fn_800D8F38;
}
