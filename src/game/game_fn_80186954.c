typedef unsigned char u8;
typedef signed short s16;
typedef struct Vec3s { s16 x, y, z; } Vec3s;
extern void* memcpy(void*, const void*, unsigned long);

void fn_80186954(void* unused0, u8* entry, Vec3s* dst)
{
    int offset = entry[0x21];
    Vec3s temp;
    (void)unused0;
    temp.x = *(s16*)(entry + 0xA);
    temp.y = *(s16*)(entry + 0xC);
    temp.z = *(s16*)(entry + 0xE) - offset;
    memcpy(dst, &temp, 6);
    temp.z = *(s16*)(entry + 0xE) + offset;
    memcpy((u8*)dst + 6, &temp, 6);
}
