unsigned int fn_80113CF8(unsigned int value)
{
    unsigned int count = ((value & 0xF) << 1) + 3;
    unsigned int result = 0x10000 << (value & 0xF);
    unsigned int digits = value >> 4;
    unsigned int i;

    for (i = 0; i < count; i++) {
        int bit = 1 << (digits & 0xF);
        if (bit != 0x2000) {
            if ((result & bit) != 0) {
                return 0;
            }
            result |= bit;
        }
        digits >>= 4;
    }
    return result;
}
