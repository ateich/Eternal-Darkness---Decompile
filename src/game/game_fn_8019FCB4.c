typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_80607120[];
extern int lbl_8064D738;
extern float lbl_80650C8C;
extern float lbl_80650C90;
extern void fn_801ED3F4();
extern void fn_8019FEE4();
extern void DCFlushRange();
extern int fn_801ED57C();
extern void fn_801ED5F4();
extern void fn_80226D28();
extern void fn_8018D0D0();
extern void fn_801ED468();
extern void fn_801ECEC8();
extern u8 fn_8017FFB8();
extern u8 fn_8017FFB0();
extern u8 fn_8017FF98();
extern void fn_80225F4C();
extern void fn_80226AB4();
extern void fn_8019FED8();
extern void fn_8019FECC();
extern void fn_8019FEC0();
extern void fn_8019FEBC();

void fn_8019FCB4(u8* object)
{
    u16 vertex_count = *(u16*)(lbl_80607120 + 2);
    u16 vertex_size = *(u16*)(lbl_80607120 + 0xA);
    u16 index_size = *(u16*)(lbl_80607120 + 0xE);
    u16 color_size = *(u16*)(lbl_80607120 + 0xC);
    u8* vertices;
    u8* indices;
    u8* colors;
    u8* entry;
    u8* color;
    u16 count;
    u16 i;
    int saved;

    fn_801ED3F4(*(int*)(object + 0x68));
    vertices = *(u8**)(object + 0x50);
    indices = *(u8**)(object + 0x54);
    colors = *(u8**)(object + 0x58);
    if (lbl_8064D738 != 0) {
        vertices += vertex_count * 6;
        indices += vertex_count * 4;
        colors += vertex_count * 4;
    }
    entry = *(u8**)(object + 0x4C);
    color = colors;
    count = *(u16*)(object + 0x90);
    for (i = 0; i < count; i++) {
        u16 j;
        fn_8019FEE4(vertices + i * 24, *(u8**)(object + 0x8C) + i * 0x3C + 0xC);
        for (j = 0; j < entry[0x20]; j++) {
            color[3] = entry[0x2B];
            color += 4;
        }
    }
    DCFlushRange(vertices, vertex_size);
    DCFlushRange(indices, index_size);
    DCFlushRange(colors, color_size);
    saved = fn_801ED57C(0);
    fn_801ED5F4(1, 0x2100, 0x7D0, 0, 0, lbl_80650C8C);
    fn_80226D28(0);
    fn_8018D0D0(object, object + 0x5C, *(short*)(object + 0xE));
    fn_801ED468(0x1B);
    fn_801ECEC8(1, 3, 0);
    fn_80225F4C(9, vertices, fn_8017FFB8());
    fn_80225F4C(0xD, indices, fn_8017FFB0());
    fn_80225F4C(0xB, colors, fn_8017FF98());
    fn_80226AB4(0x80, 5, vertex_count);
    for (i = 0; i < vertex_count; i++) {
        fn_8019FED8(i);
        fn_8019FECC(i);
        fn_8019FEC0(i);
    }
    fn_8019FEBC();
    fn_801ED5F4(0, 0, 0, 0, 0, lbl_80650C90);
    fn_801ED57C(saved);
}
