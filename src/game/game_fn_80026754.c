void fn_80026754(int x, int y, int z)
{
    volatile unsigned short* fifo = (volatile unsigned short*)0xCC008000;

    *fifo = x;
    *fifo = y;
    *fifo = z;
}
