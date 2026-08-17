void* fn_8011F9E4(void* object, int index)
{
    char* state = *(char**)((char*)object + 0x3C);
    return *(char**)(state + 0x88) + index * 0x78;
}
