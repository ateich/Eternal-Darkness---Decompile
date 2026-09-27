typedef unsigned char u8;
typedef unsigned short u16;

typedef struct BufferSetup {
    u16 unused;
    u16 color_buffer_offset;
} BufferSetup;

extern BufferSetup lbl_80607120[3];

void fn_8018FFBC(u8* destination, u8* first, u8* second, u8 count)
{
    u8* other = destination + lbl_80607120[0].color_buffer_offset * 4;
    u8* row = destination;
    int buffer;

    for (buffer = 0; buffer < 2; buffer++) {
        int i;
        for (i = 0; i < count; i++) {
            row[0] = first[0];
            row[1] = first[1];
            row[2] = first[2];
            row[3] = first[3];
            row[4] = second[0];
            row[5] = second[1];
            row[6] = second[2];
            row[7] = second[3];
            row += 8;
        }
        row = other;
    }
}
