typedef signed short s16;

int fn_80180114(void* object)
{
    if (object != 0) {
        return *(s16*)((char*)object + 0x22) & 8;
    }
    return 0;
}
