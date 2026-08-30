void fn_801A5F40(short value, int* state)
{
    *(short*)((char*)state + 0x36) = value;
    state[2] |= 8;
}
