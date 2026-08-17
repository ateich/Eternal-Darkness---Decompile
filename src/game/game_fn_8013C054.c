void fn_8013C054(float x, float y, float z)
{
    volatile float* fifo = (volatile float*)0xCC008000;

    *fifo = x;
    *fifo = y;
    *fifo = z;
}
