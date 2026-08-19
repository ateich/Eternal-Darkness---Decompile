extern void* fn_8015C28C(int);
void* fn_8015C2FC(int selector)
{
    unsigned char* slot = fn_8015C28C(selector);
    if (slot != 0 && *(signed char*)(slot + 0x8142) && *(signed char*)(slot + 0x8143))
        return slot;
    return 0;
}
