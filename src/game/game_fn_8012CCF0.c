typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 { float x, y, z; } Vec3;

extern float lbl_806501D8;
extern void fn_80125ECC(u8*);
extern void fn_8012BDCC(const float*, short*, int);
extern void fn_8012F6E8(void*);

#pragma use_lmw_stmw on
void fn_8012CCF0(u8* state, int index, Vec3* first, Vec3* second,
                 Vec3* third, int alternate)
{
    u8* definition;
    u8* entry;
    u8* runtime;
    int bits;

    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry != 0) {
        definition = *(u8**)(entry + 4);
        fn_8012BDCC((float*)first, (short*)(entry + 0x54), 6);
        fn_8012BDCC((float*)second, (short*)(entry + 0x60), 6);
        fn_8012BDCC((float*)third, (short*)(entry + 0x66), 6);
        fn_8012F6E8(entry + 0x1C);
        if (lbl_806501D8 != second->x || lbl_806501D8 != second->y ||
            lbl_806501D8 != second->z)
            *(u16*)(entry + 0x1C) = 1;
        runtime = *(u8**)(state + 0x160);
        runtime += *(u16*)(definition + 0xE) * 0x4C;
        *(u8**)(runtime + 0x48) = entry;
        *(u16*)(entry + 0xA) &= ~0x12;
        bits = alternate ? 0x10 : 2;
        *(u16*)(entry + 0xA) |= bits;
    }
}
