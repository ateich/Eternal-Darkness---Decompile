typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_801F6D90(s16, s16, s16);

int fn_8019DCF4(u8* object)
{
    int result = 1;
    u32 value = fn_801F6D90(*(s16*)(object + 0x10), *(s16*)(object + 0x12),
                           *(s16*)(object + 0x14));

    if ((object[0x101] && value > 300) || (!object[0x101] && value > 200)) {
        result = 0;
    }
    return result;
}
