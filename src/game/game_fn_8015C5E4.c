extern void* fn_8015C28C(int);

void* fn_8015C5E4(int selector, unsigned short* count)
{
    unsigned char* slot = fn_8015C28C(selector);
    void* result = *(void**)(slot + 0x10C);
    if (count != 0)
        *count = *(unsigned short*)(slot + 0x108);
    return result;
}
