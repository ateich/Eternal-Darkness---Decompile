void fn_80026744(float x, float y)
{
    volatile float* fifo = (volatile float*)0xCC008000;

    *fifo = x;
    *fifo = y;
}
