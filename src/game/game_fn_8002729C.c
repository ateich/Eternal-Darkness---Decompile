typedef unsigned short u16;

void fn_8002729C(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
