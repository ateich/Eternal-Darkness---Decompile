typedef unsigned short u16;

void fn_8019F1C0(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
