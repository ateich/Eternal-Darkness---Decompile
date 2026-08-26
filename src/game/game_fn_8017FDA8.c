void* fn_8017FDA8(void* object, int index)
{
    unsigned char count = *((unsigned char*)object + 1);
    if (index < count) {
        return *(char**)((char*)object + 0x4C) + index * 0x38 + 0xA;
    }
    return *(char**)((char*)object + 0x4C) + count * 0x38 - 0x2E;
}
