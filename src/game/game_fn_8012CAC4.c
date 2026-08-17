typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80125ECC(u8*);

#pragma use_lmw_stmw on
#pragma dont_inline on
void fn_8012CAC4(u8* state, int index, void* value)
{
    int offset;
    int i;
    u8* definition;
    u8* entry;
    int item;

    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry == 0)
        return;
    definition = *(u8**)(entry + 4);
    for (i = 0, offset = 0; i < *(u16*)(definition + 6); offset += 2, i++) {
        item = *(u16*)(*(u8**)(definition + 8) + offset);
        if (item & 0x8000) {
            item &= ~0x8000;
            fn_8012CAC4(state, item, value);
        }
        else
            *(void**)(state + 0x17C + (u16)item * 8) = value;
    }
}
#pragma dont_inline reset
