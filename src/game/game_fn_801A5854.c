typedef unsigned short u16;

void fn_801A5854(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
