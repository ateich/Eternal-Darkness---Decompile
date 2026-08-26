typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

extern int fn_800FBFB0(void);

void fn_8017E1E4(Vec3s* current, Vec3s* base, s16 radius, s16 z_offset)
{
    int mask = radius * 2 - 1;

    current->x += radius - (fn_800FBFB0() & mask) + base->x;
    current->y += radius - (fn_800FBFB0() & mask) + base->y;

    if (z_offset >= 0) {
        current->z += z_offset + (fn_800FBFB0() & 1) + base->z;
    } else {
        current->z += z_offset + -(fn_800FBFB0() & 1) + base->z;
    }
}
