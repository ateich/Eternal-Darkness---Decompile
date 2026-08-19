extern void* fn_8015C390(int);

unsigned short fn_8015C470(int selector)
{
    unsigned char* entry = fn_8015C390(selector);
    if (entry != 0)
        return *(unsigned short*)(entry + 0x20);
    return 0;
}
