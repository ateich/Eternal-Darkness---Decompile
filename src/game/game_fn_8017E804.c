typedef signed short s16;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

void fn_8017E804(ShortCoord3* current, ShortCoord3* target, int shift)
{
    current->x += (target->x - current->x) >> shift;
    current->y += (target->y - current->y) >> shift;
    current->z += (target->z - current->z) >> shift;
}
