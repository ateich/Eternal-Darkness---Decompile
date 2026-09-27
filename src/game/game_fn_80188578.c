typedef unsigned short u16;

void fn_80188578(unsigned int value)
{
    *(volatile u16*)0xCC008000 = value;
}
