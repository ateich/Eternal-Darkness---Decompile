typedef unsigned char u8;

void fn_800329E8(u8* record, u8 value)
{
    int i;

    for (i = 0; i < 11; i++, record += 0x24) {
        if (record[0x47] != 0) {
            record[0x4B] = value;
        }
    }
}
