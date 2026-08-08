typedef unsigned int u32;

void fn_80026DBC(u32 value)
{
    *(volatile u32*)0xCC008000 = value;
}
