typedef signed int s32;

extern s32 *fn_800681C8(void);

void fn_80068074(void)
{
    s32 *slots = fn_800681C8();
    s32 *slot = slots;
    s32 i = 0;

    while (slots != 0 && i < 12) {
        *slot = 0;
        slot++;
        i++;
    }
}
