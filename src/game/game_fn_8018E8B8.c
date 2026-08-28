typedef unsigned char u8;

void fn_8018E8B8(u8* object, u8 value, int channel)
{
    object[0xB + channel * 4] = value;
    object[7] |= 1 << channel;
}
