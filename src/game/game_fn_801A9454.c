typedef unsigned short u16;

void fn_801A9454(u16 value0, u16 value1, u16 value2)
{
    volatile u16* fifo = (volatile u16*)0xCC008000;
    *fifo = value0;
    *fifo = value1;
    *fifo = value2;
}
