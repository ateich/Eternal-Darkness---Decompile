typedef unsigned char u8;

void fn_8017F700(u8* source, u8* destination, u8 index)
{
    int i;
    int count;
    u8* entry;
    u8 value;

    count = destination[1];
    value = (*(u8**)(source + 0x4C))[(u8)index * 0x38 + 0x21];
    entry = *(u8**)(destination + 0x4C);
    for (i = 0; i < count; i++)
        entry[i * 0x38 + 0x21] = value;
}
