typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern s16 lbl_80606360[];
extern double lbl_80650B98;
extern void* memcpy(void*, const void*, unsigned long);

void fn_80198AAC(u8* object, u8* entry, ShortCoord3* output, int index,
                 int generated, ShortCoord3* origin, u8 count)
{
    int phase;
    s16 width;
    s16* sine;
    s16* cosine;
    u16 center;
    u16 radius;
    ShortCoord3 point;

    sine = lbl_80606360;
    cosine = lbl_80606360 + 64;

    if (index < count - 1)
        phase = (int)((float)generated * *(float*)(object + 0x30)) & 0x3f;
    else
        phase = 0;

    width = entry[0x21];
    if (object[5] & 2)
        width = (s16)-width;

    center = *(u16*)(object + 0xe);
    radius = center - width;
    point.x = origin->x + ((radius * sine[phase]) >> 7);
    point.y = origin->y + ((radius * cosine[phase]) >> 7);
    point.z = origin->z;
    memcpy(output, &point, sizeof(point));

    radius = center + width;
    point.x = origin->x + ((radius * sine[phase]) >> 7);
    point.y = origin->y + ((radius * cosine[phase]) >> 7);
    point.z = origin->z;
    memcpy(output + 1, &point, sizeof(point));
}
