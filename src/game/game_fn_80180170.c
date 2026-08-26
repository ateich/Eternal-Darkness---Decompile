typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

int fn_80180170(void* object, u32 index)
{
    u8* entries = *(u8**)((char*)object + 0x4C);
    u8* entry = entries + (u8)index * 0x38;
    int result = 0;

    if (entry[0] == 1) {
        if ((s8)entry[5] < 0) {
            result = 1;
        }
    }
    return result;
}
