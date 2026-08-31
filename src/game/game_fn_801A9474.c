typedef unsigned short u16;

void fn_801A9474(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
