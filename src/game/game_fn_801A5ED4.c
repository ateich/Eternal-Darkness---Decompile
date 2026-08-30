extern unsigned int fn_80144710(int, int, int);
void fn_801A5ED4(void* unused, int* state)
{
    if (fn_80144710(0x100, 0, 0) == 0) state[2] |= 0x1000;
}
