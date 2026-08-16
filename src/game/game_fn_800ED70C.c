void fn_800ED70C(float x, float y, float z)
{
    volatile float *fifo = (volatile float *)0xCC008000;
    *fifo = x;
    *fifo = y;
    *fifo = z;
}
