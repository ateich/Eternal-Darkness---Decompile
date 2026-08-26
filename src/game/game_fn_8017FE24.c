void fn_8017FE24(void* object, int value)
{
    unsigned char count = *((unsigned char*)object + 1);
    char* entry = *(char**)((char*)object + 0x4C);
    int i;

    for (i = 0; i < count; i++) {
        entry[0x2B] = value;
        entry += 0x38;
    }
}
