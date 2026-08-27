typedef unsigned short u16;

void fn_8018856C(u16 value)
{
    *(volatile u16*)0xCC008000 = value;
}
