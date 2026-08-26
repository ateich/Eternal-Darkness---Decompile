typedef signed short s16;
typedef unsigned short u16;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

void fn_801805A0(void* data, ShortCoord3* first, ShortCoord3* second, u16 value)
{
    u16* half = data;

    half[8] = first->x;
    half[9] = first->y;
    half[10] = first->z;
    half[11] = second->x;
    half[12] = second->y;
    half[13] = second->z;
    half[14] = value;
    half[15] = 0;
}
