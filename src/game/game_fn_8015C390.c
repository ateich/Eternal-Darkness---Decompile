extern void* fn_8015C28C(int);

void* fn_8015C390(int selector)
{
    unsigned char* slot = fn_8015C28C(selector);
    void* result = 0;
    if (*(signed char*)(slot + 0x8142) && *(signed char*)(slot + 0x8143) && slot != 0)
        result = slot + 0xA0;
    return result;
}
