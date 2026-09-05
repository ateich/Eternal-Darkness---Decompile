typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad[0xEC];
    u8 active;
    u8 rest[7];
} Entry;

extern Entry* lbl_8064D4AC;

u32 fn_801CC6DC(u32 index)
{
    return lbl_8064D4AC[index].active != 0;
}
