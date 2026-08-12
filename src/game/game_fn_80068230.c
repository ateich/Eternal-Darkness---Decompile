typedef signed int s32;

extern s32 *fn_800681C8(void);

s32 fn_80068230(void)
{
    s32 *slots;
    s32 *slot;
    s32 index;

    slots = fn_800681C8();
    index = 0;
    slot = slots;
    while (slots != 0 && *slot != 0 && index < 12) {
        slot++;
        index++;
    }

    if (index < 12) {
        return index;
    }
    return -1;
}
