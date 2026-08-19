extern void* fn_8015C390(int);

void* fn_8015C3E0(int selector)
{
    unsigned char* entry = fn_8015C390(selector);
    void* result = 0;
    if (entry != 0)
        result = *(void**)(entry + 0x24);
    return result;
}
