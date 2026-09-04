typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 fn_801C2F34(void* envelope, u16* level, u16* delta);

int fn_801C30D4(void* envelope, u16* level, u16* delta)
{
    u8 i;

    for (i = 0; i < 15; i++) {
        if (fn_801C2F34(envelope, level, delta) != 0) {
            return 1;
        }
    }
    return 0;
}
