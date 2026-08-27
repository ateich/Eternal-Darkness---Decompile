typedef unsigned char u8;
typedef signed short s16;

void fn_801879E8(void* object, const float* value)
{
    u8* target = *(u8**)((u8*)object + 0x4C);
    *(s16*)(target + 0xA) = value[0];
    *(s16*)(target + 0xC) = value[1];
    *(s16*)(target + 0xE) = value[2];
}
