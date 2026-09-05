typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad00[0x24];
    u32 flags[50];
    u8 padEC[8];
} Entry;

extern Entry* lbl_8064D4AC;
extern u8 lbl_8064D4D8;

void fn_801CC8C4(u32 index)
{
    Entry* entry = &lbl_8064D4AC[index];

    if (((u8*)entry)[0xEC] == 1 && lbl_8064D4D8 == 0) {
        ((u8*)entry)[0xEE] = 1;
    }
    lbl_8064D4AC[index].flags[lbl_8064D4D8] |= 0x20;
}
