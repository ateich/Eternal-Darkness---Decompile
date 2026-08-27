typedef unsigned char u8;
typedef unsigned short u16;

void fn_80187A44(void* object, u16 value)
{
    *(u16*)((u8*)object + 0xDC) = value;
}
