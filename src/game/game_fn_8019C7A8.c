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
    Vec3 position;
    Vec3 points[3];
    Vec3* pointBase;
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
    pointBase = points;
    entry = *(u8**)(object + 0x4C);
    color = buffers.colors;

    for (outer = 0; outer < count; outer++) {
        s16 x = *(s16*)(entry + 0xA);
        s16 z = *(s16*)(entry + 0xC);
        s16 midpointX;
        int midpointY;
        int midpointZ;
        s16 offsetX;
        s16 offsetY;
        s16 anchorX;
        s16 anchorY;
        int half;
        Vec3* point;
        int inner;
        float dx;
        float dz;

        vertex = buffers.vertices + outer * 0x18;
        position = *(Vec3*)(object + 0xC4);
        dx = (float)x - *(float*)(object + 0xC4);
        dz = (float)z - *(float*)(object + 0xC8);
        points[0] = *(Vec3*)(object + 0xD0);
        points[0].x += dx;
        points[0].y += dz;
        points[1] = *(Vec3*)(object + 0xDC);
        points[1].x += dx;
        points[1].y += dz;
        points[2] = *(Vec3*)(object + 0xE8);
        points[2].x += dx;
        points[2].y += dz;
        position.x = (float)x;
        position.y = (float)z;

        half = (s16)(points[2].x - points[0].x) >> 1;
        midpointX = (s16)(points[0].x + (float)half);
        half = (s16)(points[2].y - points[0].y) >> 1;
        midpointY = (s16)(points[0].y + (float)half);
        half = (s16)(points[2].z - points[0].z) >> 1;
        midpointZ = (s16)(points[0].z + (float)half);

        offsetX = (s16)((float)midpointX - position.x);
        anchorX = (s16)(midpointX + (s16)(offsetX * 2));
        offsetX = (s16)((midpointX - anchorX) >> 1);
        offsetY = (s16)((float)midpointY - position.y);
        anchorY = (s16)(midpointY + (s16)(offsetY * 2));
        offsetY = (s16)((midpointY - anchorY) >> 1);

        points[0].x += offsetX;
        points[0].y += offsetY;
        points[1].x += offsetX;
        points[1].y += offsetY;
        points[2].x += offsetX;
        points[2].y += offsetY;

        anchorX += offsetX;
        anchorY += offsetY;
        point = pointBase;
        for (inner = 0; inner < entry[0x20] - 1; inner++) {
            *(s16*)(vertex + 0) = (s16)point->x;
            *(s16*)(vertex + 2) = (s16)point->y;
            *(s16*)(vertex + 4) = (s16)point->z;
            point++;
            vertex += 6;
            color[3] = entry[0x2B];
            color += 4;
        }
        *(s16*)(vertex + 0) = anchorX;
        *(s16*)(vertex + 2) = anchorY;
        *(s16*)(vertex + 4) = midpointZ;
        color[3] = entry[0x2B];
        color += 4;
        entry += 0x38;
    }

    DCFlushRange(buffers.vertices, *(u16*)((u8*)setup + 0xA));
    DCFlushRange(buffers.indices, *(u16*)((u8*)setup + 0xE));
    DCFlushRange(buffers.colors, *(u16*)((u8*)setup + 0xC));
    {
        int saved = fn_801ED57C(0);
        fn_8018D0D0(object, object + 0x5C, *(s16*)(object + 0xE));
        fn_801889D8(buffers.vertices, buffers.indices, buffers.colors);
        fn_801ED57C(saved);
    }
}
