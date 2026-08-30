typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memset(void*, int, unsigned long);

void fn_801A438C(u8* data)
{
    data[0] = 0x10;
    data[1] = 0x10;
    *(u16*)(data + 4) = 0x57;
    data[3] = 0x33;
    memset(data + 0x24, 0, 6);
    memset(data + 0x2A, 0, 6);
    data[0x20] = 1;
    *(u32*)(data + 0x14) = 1;
    *(u32*)(data + 0x30) = 0;
    *(u32*)(data + 0x34) = 0;
    *(u16*)(data + 0x22) = 0x80;
}
