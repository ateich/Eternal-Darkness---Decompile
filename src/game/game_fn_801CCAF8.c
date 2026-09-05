typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad00[0x90];
    u8 field90;
    u8 pad91[0x63];
} Entry;

extern Entry* lbl_8064D4AC;

u8 fn_801CCAF8(u32 index)
{
    return lbl_8064D4AC[index].field90;
}
