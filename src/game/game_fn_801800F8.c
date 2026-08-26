typedef signed short s16;

int fn_801800F8(void* object)
{
    if (object != 0) {
        return *(s16*)((char*)object + 0x22) & 4;
    }
    return 0;
}
