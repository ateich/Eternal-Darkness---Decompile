typedef volatile float FifoFloat;

void fn_8012319C(float first, float second)
{
    FifoFloat* fifo = (FifoFloat*)0xCC008000;
    *fifo = first;
    *fifo = second;
}
