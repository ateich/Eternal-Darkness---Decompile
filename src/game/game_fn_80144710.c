typedef struct MaskPair { unsigned int first; unsigned int second; char pad[0x18]; } MaskPair;
extern MaskPair lbl_805B40F0[];

unsigned int fn_80144710(unsigned int value, int second, int index)
{
    unsigned int result;
    if (second == 0)
        result = value & lbl_805B40F0[index].second;
    else
        result = value & lbl_805B40F0[index].first;
    if (result != 0)
        result |= value & 0xC0000000;
    return result;
}
