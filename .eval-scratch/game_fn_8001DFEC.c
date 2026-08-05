struct Sub {
    unsigned char pad0[0x1C];
    unsigned int field_1C;
    unsigned int field_20;
    unsigned char pad24[0x30-0x24];
    unsigned int field_30;
    unsigned char pad34[0x3E-0x34];
    unsigned char field_3E;
    unsigned char field_3F;
    unsigned char pad40[0x44-0x40];
    unsigned char field_44;
    unsigned char pad45[0x60-0x45];
};

struct Sub2 {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_C;
    unsigned int field_10;
    unsigned int field_14;
};

struct GameState {
    unsigned char pad0[0x1C];
    struct Sub sub;
    unsigned char pad7C[0x98-0x7C];
    struct Sub2 sub2;
    unsigned char padB0[0xC0-0xB0];
    unsigned short field_C0[8][32];
    unsigned char field_2C0;
};

struct OtherState {
    unsigned char pad0[0x28];
    unsigned int field_28;
    unsigned int field_2C;
};

extern struct GameState lbl_80302400;
extern struct OtherState lbl_8023D660;

extern void fn_8020EFBC(void *);
extern void fn_8020F0F8(void *);
extern void fn_80228B50(void *, void *, int, int);

void fn_8001DFEC(unsigned char arg1, unsigned int arg2)
{
    struct GameState *g = &lbl_80302400;
    unsigned char old_5A = g->sub.field_3E;
    unsigned int old_38 = g->sub.field_1C;
    unsigned int v_4C = g->sub.field_30 & ~3u;

    g->sub.field_3E = arg1;
    g->sub.field_3F = old_5A;
    g->sub.field_20 = old_38;
    g->sub.field_1C = arg2;
    g->sub.field_30 = v_4C;

    fn_8020EFBC(&g->sub.field_44);
    fn_8020F0F8(&g->sub.field_44);

    g->sub2.field_0 = 0;
    g->sub2.field_14 = (unsigned int)&g->field_C0;
    g->sub2.field_4 = 0;
    g->sub2.field_8 = 0;
    g->sub2.field_C = 0;
    g->sub2.field_10 = 0;

    fn_80228B50(&g->field_2C0, &g->field_C0, 0, 0x100);

    {
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 32; j++) {
                g->field_C0[i][j] = 0xff;
            }
        }
    }

    lbl_8023D660.field_2C = 0xff;
    lbl_8023D660.field_28 = 0;
}
