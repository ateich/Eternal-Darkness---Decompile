extern unsigned int fn_800FBFB0();

unsigned short fn_800E4A50(void)
{
    unsigned short value = fn_800FBFB0() & 15;

    if (value == 0)
        value = 2;
    else if (value & 1)
        value++;
    if (value > 12 && (fn_800FBFB0() & 1))
        value = 12;
    return value;
}
