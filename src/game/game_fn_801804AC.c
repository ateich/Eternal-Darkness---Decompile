typedef unsigned int size_t;

extern void* memcpy(void* destination, const void* source, size_t count);

void fn_801804AC(void* object, const void* first, const void* second,
                 const void* third)
{
    memcpy((char*)object + 0x10, first, 6);
    memcpy((char*)object + 0x16, second, 6);
    memcpy((char*)object + 0x1C, third, 6);
}
