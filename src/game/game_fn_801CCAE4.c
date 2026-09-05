typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad00[0x9C];
    u8 field9C;
    u8 pad9D[0x57];
} Entry;

extern Entry* lbl_8064D4AC;

u8 fn_801CCAE4(u32 index)
{
    return lbl_8064D4AC[index].field9C;
}
