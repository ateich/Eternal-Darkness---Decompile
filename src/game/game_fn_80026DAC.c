typedef unsigned short u16;

void fn_80026DAC(u16 x, u16 y)
{
    volatile u16* fifo = (volatile u16*)0xCC008000;

    *fifo = x;
    *fifo = y;
}
