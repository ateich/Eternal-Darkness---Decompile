typedef unsigned short u16;

void fn_80086204(u16 first, u16 second, u16 third)
{
    volatile u16* fifo = (volatile u16*)0xCC008000;
    *fifo = first;
    *fifo = second;
    *fifo = third;
}
