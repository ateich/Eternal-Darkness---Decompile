typedef unsigned short u16;

extern u16 lbl_80607120[];

void fn_8018C118(u16* entries, int packed_count)
{
    u16* second;
    int group;

    second = entries;
    second += lbl_80607120[1] * 2;

    for (group = 0; group < 2; group++) {
        int i;
        for (i = 0; i < (((packed_count >> 1) & 0x7F) + 1); i++) {
            entries[0] = 0;
            entries[1] = 0;
            entries[2] = 0;
            entries[3] = 0x200;
            entries[4] = 0x200;
            entries[5] = 0;
            entries[6] = 0x200;
            entries[7] = 0x200;
            entries += 8;
        }
        entries = second;
    }
}
