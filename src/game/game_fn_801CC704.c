typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad[0x1C];
    u32 value;
    u8 rest[0xD4];
} Entry;

extern Entry* lbl_8064D4AC;

void fn_801CC704(u32 index, u32 value)
{
    lbl_8064D4AC[index].value = value;
}
