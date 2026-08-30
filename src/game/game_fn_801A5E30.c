extern float lbl_80650DA0;

void fn_801A5E30(int* state)
{
    float zero;
    state[2] = 0;
    zero = lbl_80650DA0;
    state[3] = 0x10000;
    state[4] = -1;
    *(float*)&state[5] = zero;
    *(float*)&state[6] = zero;
    *(float*)&state[7] = zero;
    *(short*)((char*)state + 0x36) = 0;
    *(short*)((char*)state + 0x38) = 0;
    *(short*)((char*)state + 0x34) = 0;
}
