typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8018EA58(u8*);

int fn_8018E8E4(u8* object)
{
    u16* counter = (u16*)(object + 0xA);
    u16* limit = (u16*)(object + 0xC);

    if (*counter >= *limit && *limit != 0) {
        *(u16*)(object + 0x22) = 8;
    }
    (*counter)++;
    fn_8018EA58(object);
    return 0;
}
