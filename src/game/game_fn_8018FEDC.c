typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern s16 lbl_80606360[];
extern double lbl_80650B08;
extern void* memcpy(void*, const void*, unsigned long);

void fn_8018FEDC(u8* self, u8* destination, int index,
                 ShortCoord3* source, u8 count)
{
    ShortCoord3 rotated;
    s16* sine;
    s16* cosine;
    int phase;
    u16 scale;

    sine = lbl_80606360;
    cosine = lbl_80606360 + 64;

    if (index < count - 1) {
        phase = (int)((float)index * *(float*)(self + 0xD0)) & 0x3F;
    } else {
        phase = 0;
    }

    scale = *(u16*)(self + 0xAE);
    rotated.x = source->x + ((scale * sine[phase]) >> 7);
    rotated.y = source->y + ((scale * cosine[phase]) >> 7);
    rotated.z = source->z;
    memcpy(destination, source, 6);
    memcpy(destination + 6, &rotated, 6);
}
