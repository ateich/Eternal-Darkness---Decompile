unsigned int fn_8011FADC(void* object, unsigned int value)
{
    unsigned int old = *(unsigned int*)((char*)object + 0x254);
    *(unsigned int*)((char*)object + 0x254) = value;
    return old;
}
