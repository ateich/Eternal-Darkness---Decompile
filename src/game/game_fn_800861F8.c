typedef unsigned short u16;

void fn_800861F8(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
