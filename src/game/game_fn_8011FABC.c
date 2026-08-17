unsigned int fn_8011FABC(void* object, unsigned int clear, unsigned int set)
{
    unsigned short old = *(unsigned short*)((char*)object + 0x2D0);
    *(unsigned short*)((char*)object + 0x2D0) &= ~clear;
    *(unsigned short*)((char*)object + 0x2D0) |= set;
    return old;
}
