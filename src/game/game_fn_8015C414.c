extern void* fn_8015C390(int);

void* fn_8015C414(int selector, unsigned short* count)
{
    unsigned char* entry = fn_8015C390(selector);
    void* result = 0;
    if (entry != 0) {
        if (count != 0)
            *count = *(unsigned short*)(entry + 0x50);
        result = *(void**)(entry + 0x54);
    } else {
        *count = 0;
    }
    return result;
}
