typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad00[0x24];
    u32 flags;
    u8 pad28[0xA6];
    u16 fieldCE;
    u8 padD0[0x24];
} Entry;

extern Entry* lbl_8064D4AC;
extern u16 lbl_8064C2F0[4];

void fn_801CCC3C(u32 index, u8 value)
{
    Entry* entry = &lbl_8064D4AC[index];
    entry->fieldCE = lbl_8064C2F0[value];
    entry->flags |= 0x80;
}
