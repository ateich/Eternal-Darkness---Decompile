unsigned int fn_8011FA8C(void* object, unsigned int clear, unsigned int set)
{
    unsigned int old = *(unsigned int*)((char*)object + 0x254);
    *(unsigned int*)((char*)object + 0x254) &= ~clear;
    *(unsigned int*)((char*)object + 0x254) |= set;
    return old;
}
