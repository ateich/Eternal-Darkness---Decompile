typedef unsigned short u16;

void fn_8019F1CC(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
