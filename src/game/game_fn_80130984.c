typedef volatile float HardwareFloat;

void fn_80130984(float x, float y, float z)
{
    HardwareFloat* fifo = (HardwareFloat*)0xCC008000;
    *fifo = x;
    *fifo = y;
    *fifo = z;
}
