typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;


typedef struct Entry {
    u8 pad0[0xA];
    s16 position[3];
    u8 pad10[0x28];
} Entry;

extern void fn_80186F70(s16* output, int count, int magnitude, float step,
                        float base);

void fn_80187320(Entry* entry, u16* flags, s16* bounds, int axis, int start,
                 int end, int base, int magnitude, float step, int delta)
{
    int index;
    u32 mask;
    float current;

    index = start;
    mask = 1 << (start + 3);
    current = (float)base;

    while (index < end) {
        int hit = 0;
        if ((*flags & mask) != 0) {
            entry->position[axis] += delta;
            if (entry->position[axis] >= bounds[index]) {
                hit = 1;
            }
        } else {
            entry->position[axis] -= delta;
            if (entry->position[axis] <= bounds[index]) {
                hit = 1;
            }
        }
        if (hit) {
            entry->position[axis] = bounds[index];
            fn_80186F70(&bounds[index], 1, magnitude, step, current);
            if (entry->position[axis] < bounds[index]) {
                *flags |= mask;
            } else {
                *flags &= ~mask;
            }
        }
        current += step;
        mask <<= 1;
        entry++;
        index++;
    }
}
