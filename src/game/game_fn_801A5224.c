typedef unsigned char u8;
typedef unsigned long u32;

typedef struct Triple {
    u32 x;
    u32 y;
    u32 z;
} Triple;

void fn_801A5224(u8* object, u8* config)
{
    *(Triple*)(object + 0x8c) = *(Triple*)(config + 0x14);
    *(Triple*)(object + 0x98) = *(Triple*)(config + 0x20);
    *(Triple*)(object + 0xa4) = *(Triple*)(config + 0x2c);
    *(Triple*)(object + 0xb0) = *(Triple*)(config + 0x38);
    object[0xbc] = config[0x48];
}
