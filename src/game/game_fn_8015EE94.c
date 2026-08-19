extern unsigned int fn_8015EAA0(void*);

int fn_8015EE94(void* object)
{
    unsigned int entry = fn_8015EAA0(object);
    if ((int)(entry & 0x3F) == 2 && (int)((entry >> 6) & 0x1FF) == 0xFF)
        return 1;
    return 0;
}
