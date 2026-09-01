typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct EffectNode { struct EffectNode* next; int state, object_id, timer, handle, resource; u16 kind, value; u8 x, y, flushed, queued; } EffectNode;
extern EffectNode* lbl_8064D304;
extern int lbl_8064D300, lbl_8064C2D0;
extern u8 lbl_8060B060[];
extern unsigned int fn_801B191C(void);
extern int fn_800E4594(void), fn_801AD7C0(int, int);
extern void fn_801B151C(int, void*, int, int, void*), fn_801B17B0(int), fn_801B17A8(int);
extern void fn_801ACF80(EffectNode*), fn_801ACFB0(void), fn_801AD46C(u8*, u8*), fn_801ACCA0(int, int);
extern void fn_801E8328(int, int), fn_801A98F4(u16, u8), DCFlushRange(void*, unsigned long), fn_801ACFE8(u32);
static int clamp127(int v) { return v > 127 ? 127 : v > 0 ? v : 0; }
void fn_801AD08C(void)
{
    EffectNode* node = lbl_8064D304;
    int active, a, b; u8 x, y;
    if (node == 0) return;
    switch (node->state) {
    case 1:
        if (fn_801B191C() == 3) break;
        active = 1;
        if (node->object_id != lbl_8064C2D0 && lbl_8064D300 != 3 && lbl_8064D300 != 2) {
            a = fn_800E4594();
            if (node->kind != 0 || node->queued == 1) { active = 0; node->state = 7; DCFlushRange(node, 0x20); }
            node->resource = fn_801AD7C0(node->resource, 1);
            fn_801B151C(a, lbl_8060B060, 0x3f, node->resource, fn_801ACFE8);
            if (node->kind != 0 || node->queued == 1) { lbl_8064D300 = 4; fn_801B17B0(4); }
            else { lbl_8064D300 = 3; fn_801B17B0(1); }
            fn_801B17A8(node->handle); lbl_8064C2D0 = node->object_id;
        }
        if (active) fn_801ACF80(node);
        break;
    case 7:
        if (node->flushed == 1) { fn_801B17B0(1); lbl_8064D300 = 3; if (node->kind != 0) fn_801E8328(0x18, node->kind); fn_801ACF80(node); }
        break;
    case 5:
        fn_801AD46C(&x, &y); a = clamp127(x + (node->x - x) / node->timer); b = clamp127(y + (node->y - y) / node->timer);
        fn_801ACCA0(a, b); node->timer--; if (node->timer == 0 || (a == node->x && b == node->y)) { fn_801ACF80(node); node->timer = 0; }
        break;
    case 2:
        if (fn_801B191C() != 3) { if (lbl_8064D300 == 3 || lbl_8064D300 == 2) { fn_801B17B0(0); fn_801ACFB0(); } else fn_801B17B0(0); fn_801ACF80(node); }
        break;
    case 3:
        if (fn_801B191C() != 3) { if (lbl_8064D300 == 3) { fn_801B17B0(2); lbl_8064D300 = 2; } fn_801ACF80(node); }
        break;
    case 4:
        if (fn_801B191C() != 3) { if (lbl_8064D300 == 2) { fn_801B17B0(1); lbl_8064D300 = 3; } fn_801ACF80(node); }
        break;
    case 8: if (node->timer != 0) node->timer--; else fn_801ACF80(node); break;
    case 9: fn_801A98F4(node->value, node->x); fn_801ACF80(node); break;
    }
}
