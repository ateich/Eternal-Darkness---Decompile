typedef unsigned short u16;

void fn_8019FED8(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
