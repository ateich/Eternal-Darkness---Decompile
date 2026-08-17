typedef unsigned char u8;

extern void fn_80125ECC(u8*);

void fn_8012D074(u8* state, int index, float value)
{
    u8* entry;

    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry != 0)
        *(float*)(entry + 0x88) = value;
}
