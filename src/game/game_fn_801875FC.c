typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

#pragma use_lmw_stmw on

extern int fn_800FBFB0(void);

void fn_801875FC(u8* entry, u16* flags, s16* bounds, int axis, int start,
                 int end, s16* first, s16* second, int add, int delta)
{
    s16* bound = &bounds[start];
    int offset = axis * 2;
    int a = second[axis];
    int b = first[axis];
    int peak = add + (a > b ? a : b);
    float step = (float)(2 * peak - b - a) / (float)(end - start);
    int step_integer = (int)step;
    float current = (float)b;
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
            value = fn_800FBFB0() % step_integer;
            if (step < 0.0f) value = -value;
            *bound = (s16)(current + (float)value);
            if (*coordinate < *bound) *flags |= mask;
            else *flags &= ~mask;
        }
        current += step;
        if (current > (float)peak) step = -step;
        mask <<= 1;
        entry += 0x38;
        bound++;
        index++;
    }
}
