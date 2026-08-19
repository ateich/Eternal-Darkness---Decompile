extern void* fn_8015C28C(int);

void* fn_8015C5A0(int selector, unsigned short* count)
{
    unsigned char* slot = fn_8015C28C(selector);
    void* result = *(void**)(slot + 0xB4);
    if (count != 0)
        *count = *(unsigned short*)(slot + 0xB0);
    return result;
}
