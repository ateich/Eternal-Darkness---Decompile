typedef unsigned char u8;

void fn_80190500(void* object, void* value)
{
    *(void**)((u8*)object + 0x98) = value;
}
