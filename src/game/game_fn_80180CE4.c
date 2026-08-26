typedef unsigned char u8;

void fn_80180CE4(u8* object, int enabled)
{
    if (enabled != 0) {
        object[0x91] |= 0x80;
    } else {
        object[0x91] &= 0x7F;
    }
}
