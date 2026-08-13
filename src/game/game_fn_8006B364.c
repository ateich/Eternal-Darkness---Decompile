typedef signed int s32;
typedef unsigned char u8;

extern void fn_8006B488(s32 first, s32 last, s32 *count, void *mask_a,
                       void *mask_b);

void fn_8006B364(u8 *state)
{
    s32 count = 0;

    state[1] = 0;
    state[2] = 0;
    state[3] = 0;
    *(s32 *)(state + 0x3C) = -1;
    *(s32 *)(state + 0x40) = -1;
    *(s32 *)(state + 0x44) = -1;
    fn_8006B488(0, 0x1F, &count, state + 0x2C, state + 0x24);
    fn_8006B488(0x20, 0x28, &count, state + 0x30, state + 0x28);
    state[0] = count;
    *(s32 *)(state + 0x20) = 0;
    *(s32 *)(state + 0x0C) = 0;
    *(s32 *)(state + 0x10) = 0;
    *(s32 *)(state + 0x14) = 0;
    *(s32 *)(state + 0x18) = 0;
    *(s32 *)(state + 0x1C) = 0;
    state[8] = 5;
}
