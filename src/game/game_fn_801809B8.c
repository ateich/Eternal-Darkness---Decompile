typedef unsigned char u8;
typedef signed int s32;

void fn_801809B8(u8* object, u8 value)
{
    s32 count = object[1];
    s32 i;
    u8* entry = *(u8**)(object + 0x4C);

    for (i = 0; i < count; i++) {
        entry[0x21] = value;
        entry += 0x38;
    }
}
