typedef signed short s16;
typedef unsigned char u8;

typedef struct ShortCoord3 { s16 x; s16 y; s16 z; } ShortCoord3;
typedef struct Vec3 { float x; float y; float z; } Vec3;
extern Vec3 lbl_8023B0A0;
extern float lbl_80650B94;
extern float lbl_80650BA8;
extern float lbl_80650BAC;
extern void fn_8018FEDC(u8*, u8*, int, ShortCoord3*, int);
extern void fn_80198AAC(void*, void*, void*, int, int, void*, int);
extern float fn_80179370(float, float);
extern void fn_80198154(void*, void*, int, Vec3*, Vec3*);
extern void fn_80198318(void*, int, int, void*, int, int);
extern void fn_80198BF4(void*, float);
extern void* memcpy(void*, const void*, unsigned long);

void fn_80197D20(u8* object, u8* vertices, void* info, u8 flags)
{
    ShortCoord3 position;
    Vec3 direction;
    Vec3 initial = lbl_8023B0A0;
    u8 count = object[1];
    unsigned int half_count = (count >> 1) & 0x7f;
    u8* entry = *(u8**)(object + 0x4c);
    u8* saved_entry;
    int count_index;
    int index;
    int generated;
    int saved_half_count = half_count;
    int full_count = object[1];

    saved_entry = entry;
    generated = 0;
    index = 0;
    while (index < count) {
        u8* destination = (u8*)((ShortCoord3*)vertices + (index << 1));
        if (index < (u8)half_count) {
            fn_8018FEDC(object, destination, index,
                        (ShortCoord3*)info, saved_half_count);
        } else {
            fn_80198AAC(object + 0xa0, saved_entry, destination, index,
                        generated, info, full_count);
            generated++;
        }
        saved_entry += 0x38;
        index++;
    }

    memcpy(&position, object + 0x16, 6);
    direction.x = lbl_80650BA8;
    direction.y = lbl_80650B94;
    direction.z = fn_80179370((float)position.y, (float)position.x);
    fn_80198154(object + 0x10, vertices, (object[1] & 0x7f) * 2,
                &initial, &direction);

    for (index = 0; index < count; index++) {
        ShortCoord3* delta =
            (ShortCoord3*)(entry + index * 0x38 + 0x10);
        ShortCoord3* first = (ShortCoord3*)vertices + (index << 1);
        ShortCoord3* second = first + 1;
        delta->x = second->x - first->x;
        delta->y = second->y - first->y;
        delta->z = second->z - first->z;
    }

    fn_80198318(entry, half_count, count, vertices, count, 2);
    if (flags & 0x80) {
        u8* scale_entry = entry;
        for (count_index = 0; count_index < count; scale_entry += 0x38, count_index++)
            fn_80198BF4(scale_entry + 0x10, lbl_80650BAC);
    }
}
