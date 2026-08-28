typedef unsigned char u8;
typedef unsigned short u16;

void fn_8018C540(u8* dest, const u8* color, u8 repeats, int run_length, u16 offset)
{
    u8* second = dest + offset * 4;
    int group;

    for (group = 0; group < 2; group++) {
        int i;
        for (i = 0; i < repeats; i++) {
            int j;
            for (j = 0; j < run_length; j++) {
                dest[0] = color[0];
                dest[1] = color[1];
                dest[2] = color[2];
                dest[3] = color[3];
                dest += 4;
            }
        }
        dest = second;
    }
}
