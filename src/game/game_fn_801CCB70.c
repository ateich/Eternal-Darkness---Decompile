typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad00[0x24];
    u32 flags[4];
    u8 pad34[0xC0];
} Entry;

extern Entry* lbl_8064D4AC;
extern u8 lbl_8064D4D8;

void fn_801CCB70(u32 index)
{
    lbl_8064D4AC[index].flags[lbl_8064D4D8] |= 0x40;
}
