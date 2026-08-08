typedef unsigned short u16;

void fn_800272A8(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
