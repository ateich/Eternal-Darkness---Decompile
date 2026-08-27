typedef unsigned short u16;

void fn_80185000(unsigned char* self, u16 value)
{
    *(u16*)(self + 0xAA) = value;
}
