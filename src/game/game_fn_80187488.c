typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

#pragma use_lmw_stmw on

extern int fn_800FBFB0(void);

void fn_80187488(u8* entry, u16* flags, s16* bounds, int axis, int start,
                 int end, s16* first, s16* second, int add, int delta)
{
    s16* bound = &bounds[start];
    int offset = axis * 2;
    int a = second[axis];
    int b = first[axis];
    int peak = add + (a > b ? a : b);
    int step = (2 * peak - b - a) / (end - start);
    int current = b;
    int index = start;
    u32 mask = 1 << (start + 3);
    while (index < end) {
        int hit = 0;
        s16* coordinate = (s16*)(entry + 0xA + offset);
        if ((*flags & mask) != 0) {
            *coordinate += delta;
            if (*coordinate >= *bound) hit = 1;
        } else {
            *coordinate -= delta;
            if (*coordinate <= *bound) hit = 1;
        }
        if (hit) {
            int value;
            *coordinate = *bound;
            value = fn_800FBFB0() % step;
            if (step < 0) value = -value;
            *bound = (s16)(current + value);
            if (*coordinate < *bound) *flags |= mask;
            else *flags &= ~mask;
        }
        current += step;
        if (current > peak) step = -step;
        mask <<= 1;
        entry += 0x38;
        bound++;
        index++;
    }
}
