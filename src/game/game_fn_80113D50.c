extern int fn_801E75A4(unsigned int, int);

unsigned int fn_80113D50(unsigned int value)
{
    int type = fn_801E75A4((value >> 16) & 7, 0);
    int low = fn_801E75A4(value & 0xF, 0);
    int middle = fn_801E75A4(value & 0x1F0, 0);
    int high = fn_801E75A4(value & 0x1E00, 0);
    unsigned int result = type | (low << 4);

    switch (type) {
    case 0:
        result |= (middle << 8) | (high << 12);
        break;
    case 1:
        result |= ((middle << 12) | 0xD00) | (high << 16) | 0x00D00000;
        break;
    case 2:
        result |= ((middle << 12) | 0x00DD0D00) | (high << 24) | 0xD0000000;
        break;
    }
    return result;
}
