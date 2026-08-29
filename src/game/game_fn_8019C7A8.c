typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Buffers {
    u8* vertices;
    u8* indices;
    u8* colors;
} Buffers;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u8 lbl_80607120[];
extern int lbl_8064D738;
extern void fn_8018D788(int, void*, Buffers*, u16);
extern void DCFlushRange(void*, u32);
extern int fn_801ED57C(int);
extern void fn_8018D0D0(void*, void*, s16);
extern void fn_801889D8(void*, void*, void*);

void fn_8019C7A8(u8* object)
{
    u32 setup[4];
    Buffers buffers;
    Vec3 points[3];
    u8* entry;
    u8* color;
    u8* vertex;
    u8 count;
    int outer;

    setup[0] = *(u32*)(lbl_80607120 + 0);
    setup[1] = *(u32*)(lbl_80607120 + 4);
    setup[2] = *(u32*)(lbl_80607120 + 8);
    setup[3] = *(u32*)(lbl_80607120 + 12);
    count = object[1];
    fn_8018D788(lbl_8064D738, object, &buffers, *(u16*)((u8*)setup + 2));
    entry = *(u8**)(object + 0x4C);
    color = buffers.colors;

    for (outer = 0; outer < count; outer++) {
        int x = *(s16*)(entry + 0xA);
        int z = *(s16*)(entry + 0xC);
        int half;
        int opposite;
        int inner;
        float dx = (float)x - *(float*)(object + 0xC4);
        float dz = (float)z - *(float*)(object + 0xC8);

        points[0].x = *(float*)(object + 0xD0) + dx;
        points[0].y = *(float*)(object + 0xD4) + dz;
        points[0].z = *(float*)(object + 0xD8);
        points[1].x = *(float*)(object + 0xDC) + dx;
        points[1].y = *(float*)(object + 0xE0) + dz;
        points[1].z = *(float*)(object + 0xE4);
        points[2].x = *(float*)(object + 0xE8) + dx;
        points[2].y = *(float*)(object + 0xEC) + dz;
        points[2].z = *(float*)(object + 0xF0);

        half = (s16)(points[2].x - points[0].y) / 2;
        opposite = (s16)(points[2].z - points[1].z) / 2;
        points[0].x += half;
        points[0].y += opposite;
        points[1].x += half;
        points[1].y += opposite;
        points[2].x += half;
        points[2].y += opposite;

        vertex = buffers.vertices + outer * 0x18;
        for (inner = 0; inner < entry[0x20] - 1; inner++) {
            *(s16*)(vertex + 0) = (s16)points[inner].x;
            *(s16*)(vertex + 2) = (s16)points[inner].y;
            *(s16*)(vertex + 4) = (s16)points[inner].z;
            vertex += 6;
            color[3] = entry[0x2B];
            color += 4;
        }
        *(s16*)(vertex + 0) = (s16)(x + half);
        *(s16*)(vertex + 2) = (s16)(z + opposite);
        *(s16*)(vertex + 4) = (s16)points[0].z;
        color[3] = entry[0x2B];
        color += 4;
        entry += 0x38;
    }

    DCFlushRange(buffers.vertices, *(u16*)(lbl_80607120 + 0xA));
    DCFlushRange(buffers.indices, *(u16*)(lbl_80607120 + 0xE));
    DCFlushRange(buffers.colors, *(u16*)(lbl_80607120 + 0xC));
    {
        int saved = fn_801ED57C(0);
        fn_8018D0D0(object, object + 0x5C, *(s16*)(object + 0xE));
        fn_801889D8(buffers.vertices, buffers.indices, buffers.colors);
        fn_801ED57C(saved);
    }
}
