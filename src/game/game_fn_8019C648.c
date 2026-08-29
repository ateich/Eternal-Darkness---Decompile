typedef unsigned char u8;
typedef unsigned short u16;

void fn_8019C648(u8* object)
{
    int i;
    int count;
    u8* data;

    count = object[1];
    data = object + 0x8C;
    for (i = 0; i < count; i++) {
        *(u16*)(data + 0x28 + i * 2) = 0;
        data[i] = 0;
        data[i + 8] = 0;
        data[i + 0x10] = 0;
        data[i + 0x18] = 0;
        data[i + 0x20] = 0;
    }
    data[0x20] |= 4;
}
