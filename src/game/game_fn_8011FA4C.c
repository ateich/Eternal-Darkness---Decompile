void* fn_8011FA4C(void* object, int index)
{
    char* state = *(char**)((char*)object + 0x3C);
    return *(char**)(state + 0x90) + index * 0x78;
}
