typedef unsigned char u8;

extern float lbl_806501D8;
extern void fn_80125ECC(u8*);

float fn_8012D01C(u8* state, int index)
{
    u8* entry;

    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry != 0)
        return *(float*)(entry + 0x88);
    return lbl_806501D8;
}
