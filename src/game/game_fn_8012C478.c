typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Slot { unsigned int value; u16 flags; u16 pad; } Slot;
typedef struct State { u8 pad[0x17C]; Slot slots[32]; } State;

#pragma use_lmw_stmw on

extern void fn_80125ECC(u8*);

void fn_8012C478(State* object, int index, int enabled)
{
    u8* state = (u8*)object;
    u8* definition;
    int offset;
    int i;
    u8* entry;
    int item;
    signed char child;

    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry == 0)
        return;
    definition = *(u8**)(entry + 4);
    if (enabled)
        *(u16*)(entry + 8) |= 1;
    else
        *(u16*)(entry + 8) &= ~1;
    for (i = 0, offset = 0; i < *(u16*)(definition + 6); offset += 2, i++) {
        item = *(u16*)(*(u8**)(definition + 8) + offset);
        if (item & 0x8000) {
            item &= ~0x8000;
            fn_8012C478(object, item, enabled);
        } else if (enabled) {
            object->slots[(u16)item].flags |= 1;
        } else {
            object->slots[(u16)item].flags &= ~1;
        }
    }
    if (enabled) {
        child = *(signed char*)(definition + 0xC);
        if (child != -1)
            object->slots[child].flags &= ~1;
        child = *(signed char*)(definition + 0xD);
        if (child != -1)
            object->slots[child].flags &= ~1;
    }
}
