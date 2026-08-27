void fn_80188648(float first, float second, float third)
{
    volatile float* fifo = (volatile float*)0xCC008000;
    *fifo = first;
    *fifo = second;
    *fifo = third;
}
