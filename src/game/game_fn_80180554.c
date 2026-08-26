typedef signed short s16;
typedef unsigned short u16;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern void fn_801805A0(void*, ShortCoord3*, ShortCoord3*, u16);

void fn_80180554(void* data, ShortCoord3* first, ShortCoord3* second,
                 ShortCoord3* third, u16 value, u16 tail)
{
    u16* half = data;

    half[4] = value;
    half[5] = first->x;
    half[6] = first->y;
    half[7] = first->z;
    fn_801805A0(data, second, third, tail);
}
