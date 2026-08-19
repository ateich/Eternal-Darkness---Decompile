extern void* fn_8015C28C(int);
void* fn_8015C348(int selector)
{
    unsigned char* slot = fn_8015C28C(selector);
    if (*(signed char*)(slot + 0x8142) && *(signed char*)(slot + 0x8143))
        return slot + 0x20;
    return 0;
}
