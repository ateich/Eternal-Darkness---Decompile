typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Slot { unsigned int value; u16 flags; u16 pad; } Slot;
typedef struct State { u8 pad[0x17C]; Slot slots[32]; } State;

extern void fn_80125ECC(void *);
extern void fn_8012C478(State*, int, int);

void fn_8012C5B0(State* object, int index)
{
    u8* state = (u8*)object;
    signed char child;
    u8* definition;

    fn_80125ECC(state);
    fn_8012C478(object, index, 0);
    definition = *(u8**)(*(u8**)(*(u8***)(state + 0x240) + index) + 4);
    child = *(signed char*)(definition + 0xD);
    if (child != -1)
        object->slots[child].flags |= 1;
}
