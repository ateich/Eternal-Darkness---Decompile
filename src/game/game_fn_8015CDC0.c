extern void fn_8020D250(void*, int, int);

void fn_8015CDC0(int message, unsigned char* state)
{
    fn_8020D250(*(void**)(state + 0x2064), message, 1);
}
