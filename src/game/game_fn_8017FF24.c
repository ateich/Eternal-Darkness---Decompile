void fn_8017FF24(void* object, unsigned char clear, unsigned char set)
{
    *((unsigned char*)object + 3) &= ~clear;
    *((unsigned char*)object + 3) |= set;
}
