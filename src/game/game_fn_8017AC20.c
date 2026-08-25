extern const float lbl_80650860;
extern const char lbl_80250D00[];

extern void fn_800F8BAC(const char*, const char*, int);

int fn_8017AC20(int scale, unsigned int bits, float value)
{
    int result = (int)(value * (1 << scale));
    const char* messages = lbl_80250D00;
    /* Deliberately relies on MWCC's negative-left-shift behavior for retail codegen. */
    unsigned int mask = bits == 32 ? -1 : -1 << bits;

    if (result != 0) {
        if (value < lbl_80650860) {
            if ((mask & result) != mask) {
                fn_800F8BAC(messages + 0x1A0, messages + 0x1BC, 2914);
            }
        } else if ((result & mask) != 0) {
            fn_800F8BAC(messages + 0x1C8, messages + 0x1BC, 2918);
        }
    }
    return result;
}
