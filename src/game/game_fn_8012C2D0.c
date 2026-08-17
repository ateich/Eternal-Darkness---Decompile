typedef unsigned char u8;
typedef unsigned short u16;

void fn_8012C2D0(u8* state)
{
    *(u16*)(state + 8) &= ~0x36;
    state[0x2F] = 0;
    state[0x2E] = 0;
    state[0x2D] = 0;
    state[0x2C] = 0;
    state[0x33] = 0;
    state[0x32] = 0;
    state[0x31] = 0;
    state[0x30] = 0;
    state[0x3B] = 0;
    state[0x3A] = 0;
    state[0x39] = 0;
    state[0x38] = 0;
    state[0x37] = 0;
    state[0x36] = 0;
    state[0x35] = 0;
    state[0x34] = 0;
}
