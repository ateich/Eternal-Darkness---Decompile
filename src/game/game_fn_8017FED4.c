int fn_8017FED4(void* object)
{
    return *((unsigned char*)object + 0x60) == 1 &&
           *((signed char*)object + 0x65) < 0;
}
