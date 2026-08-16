void fn_800EE410(unsigned char value)
{
    *(volatile unsigned char *)0xCC008000 = value;
}
