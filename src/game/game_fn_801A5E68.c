extern void fn_801A5E30(int*);
void fn_801A5E68(int* state, int mode)
{
    if (mode == 1 || mode == 2) {
        fn_801A5E30(state);
        state[2] |= 0x400;
    }
}
