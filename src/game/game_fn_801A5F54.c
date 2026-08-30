void fn_801A5F54(short value, int* state)
{
    *(short*)((char*)state + 0x38) = value;
    state[2] |= 8;
    if (state[1] == 1 && value < 0) {
        *(short*)((char*)state + 0x38) = -value;
        state[2] |= 0x40;
    }
}
