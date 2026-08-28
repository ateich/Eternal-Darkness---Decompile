typedef signed short s16;
typedef unsigned char u8;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern void fn_8018FEDC(u8*, u8*, int, ShortCoord3*, u8);

void fn_80190280(u8* self, u8* vertices, u8* colors, ShortCoord3* position)
{
    int vertex_offset;
    u8 count;
    int entry;
    u8* record;

    entry = 0;
    vertex_offset = 0;
    record = *(u8**)(self + 0x4C);
    count = self[1];
    while (entry < count) {
        int i;

        fn_8018FEDC(self, vertices + vertex_offset, entry, position, count);
        i = 0;
        while (i < record[0x20]) {
            colors[3] = record[0x2B + i * 4];
            colors += 4;
            i++;
        }
        record += 0x38;
        vertex_offset += 0xC;
        entry++;
    }
}
