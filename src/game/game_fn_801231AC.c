typedef unsigned short u16;
typedef volatile u16 FifoHalf;

void fn_801231AC(u16 first, u16 second, u16 third)
{
    FifoHalf* fifo = (FifoHalf*)0xCC008000;
    *fifo = first;
    *fifo = second;
    *fifo = third;
}
