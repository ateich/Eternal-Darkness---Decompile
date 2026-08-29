typedef signed short s16;
typedef unsigned char u8;

void fn_80198420(s16* base, u8* entries, u8 packed, s16* output,
                 int scale)
{
    int count = (packed >> 1) & 0x7F;
    int index = 0;
    s16* duplicate = output + 3;

    output += (packed & 0xFE) * 3;
    entries += count * 0x38;

    for (; index < count; index++) {
        output[0] = duplicate[0] = base[0] + *(s16*)(entries + 0x10) * scale;
        output[1] = duplicate[1] = base[1] + *(s16*)(entries + 0x12) * scale;
        output[2] = duplicate[2] = base[2] + *(s16*)(entries + 0x14) * scale;
        entries += 0x38;
        output += 6;
        duplicate += 6;
    }
}
