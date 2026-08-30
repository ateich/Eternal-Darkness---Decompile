typedef unsigned short u16;

void fn_801A5848(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
