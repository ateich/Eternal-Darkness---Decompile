void fn_801409AC(float x, float y, float z)
{
    volatile float* fifo = (volatile float*)0xCC008000;
    *fifo = x;
    *fifo = y;
    *fifo = z;
}
