typedef struct MaskThresholds {
    unsigned int first;
    unsigned int second;
    short low[4];
    short extra[4];
    short high[4];
} MaskThresholds;

extern MaskThresholds lbl_805B40F0[];
extern unsigned int fn_80144710(unsigned int, int, int);

unsigned int fn_80144760(unsigned int flags, int side, short distance, int index)
{
    MaskThresholds* limits = &lbl_805B40F0[index];
    unsigned int result;
    int value;

    if (distance <= 0)
        return fn_80144710(flags, side, index);

    result = flags & (side ? limits->first : limits->second);
    result &= 0xFFFF00FF;
    value = distance;

    if (flags & 0x00010000) {
        int negative = -value;
        if (limits->low[0] < negative && limits->high[0] >= negative)
            result |= 0x00010000;
    }
    if ((flags & 0x00020000) && limits->low[0] > value && limits->high[0] <= value)
        result |= 0x00020000;
    if (flags & 0x00040000) {
        int negative = -value;
        if (limits->low[1] < negative && limits->high[1] >= negative)
            result |= 0x00040000;
    }
    if ((flags & 0x00080000) && limits->low[1] > value && limits->high[1] <= value)
        result |= 0x00080000;
    if (flags & 0x00100000) {
        int negative = -value;
        if (limits->low[2] < negative && limits->high[2] >= negative)
            result |= 0x00100000;
    }
    if ((flags & 0x00200000) && limits->low[2] > value && limits->high[2] <= value)
        result |= 0x00200000;
    if (flags & 0x00400000) {
        int negative = -value;
        if (limits->low[3] < negative && limits->high[3] >= negative)
            result |= 0x00400000;
    }
    if ((flags & 0x00800000) && limits->low[3] > value && limits->high[3] <= value)
        result |= 0x00800000;

    if (result != 0)
        result |= flags & 0xC0000000;
    return result;
}
