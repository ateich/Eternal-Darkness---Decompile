typedef unsigned char u8;
typedef unsigned short u16;

extern u16 lbl_80607120[];
extern unsigned int fn_800FBFB0(void);
extern void* memcpy(void*, const void*, unsigned int);

void fn_8018C6EC(u8* dest, const u8* color, u8 repeats, int run_length, u16 offset)
{
    u8* start = dest;
    int i;

    for (i = 0; i < repeats; i++) {
        int j;
        for (j = 0; j < run_length; j++) {
            dest[0] = color[0];
            dest[1] = color[1];
            dest[2] = color[2] - (fn_800FBFB0() & 0x1F);
            dest[3] = color[3];
            dest += 4;
        }
    }
    memcpy(start + offset * 4, start, lbl_80607120[6]);
}
