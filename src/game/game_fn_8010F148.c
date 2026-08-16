void fn_8010F148(unsigned short a, unsigned short b, unsigned short c)
{
    volatile unsigned short* reg = (volatile unsigned short*)0xCC008000;
    reg[0] = a;
    reg[0] = b;
    reg[0] = c;
}
