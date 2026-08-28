typedef unsigned int u32;

void fn_80191204(unsigned char* data, u32 value)
{
    *(u32*)(data + 0xB8) = value;
}
