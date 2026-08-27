typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

#pragma use_lmw_stmw on

extern void fn_80186C88(s16* output, int count, int step, int base, int magnitude);

void fn_801871F0(u8* entry, u16* flags, s16* bounds, int axis, int start,
                 int end, int base, int step, int magnitude, int delta)
{
    s16* bound;
    int offset;
    int index;
    u32 mask;

    index = start;
    mask = 1 << (start + 3);
    bound = &bounds[start];
    offset = axis * 2;

    while (index < end) {
        int hit = 0;
        if ((*flags & mask) != 0) {
            *(s16*)(entry + 0xA + offset) += delta;
            if (*(s16*)(entry + 0xA + offset) >= *bound) {
                hit = 1;
            }
        } else {
            *(s16*)(entry + 0xA + offset) -= delta;
            if (*(s16*)(entry + 0xA + offset) <= *bound) {
                hit = 1;
            }
        }
        if (hit) {
            *(s16*)(entry + 0xA + offset) = *bound;
            fn_80186C88(bound, 1, step, base, magnitude);
            if (*(s16*)(entry + 0xA + offset) < *bound) {
                *flags |= mask;
            } else {
                *flags &= ~mask;
            }
        }
        base += step;
        mask <<= 1;
        entry += 0x38;
        bound++;
        index++;
    }
}
