typedef unsigned char u8;
typedef unsigned short u16;

extern u16 lbl_80607120[3][2];

void fn_8018FFBC(u8* destination, const u8* first, const u8* second, u8 count)
{
    u16 color_buffer_offset = lbl_80607120[0][1];
    u8* other = destination + color_buffer_offset * 4;
    int buffer;

    for (buffer = 0; buffer < 2; buffer++) {
        int i;
        for (i = 0; i < count; i++) {
            destination[0] = first[0];
            destination[1] = first[1];
            destination[2] = first[2];
            destination[3] = first[3];
            destination[4] = second[0];
            destination[5] = second[1];
            destination[6] = second[2];
            destination[7] = second[3];
            destination += 8;
        }
        destination = other;
    }
}
