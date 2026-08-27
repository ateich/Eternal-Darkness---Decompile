typedef unsigned short u16;

void fn_80188560(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
