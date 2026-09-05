typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad00[0xD4];
    u8 fieldD4;
    u8 padD5[0x1F];
} Entry;

extern Entry* lbl_8064D4AC;
extern u8 lbl_8064D4D8;
extern void fn_801C7580(Entry*, u8);

void fn_801CCB34(u32 index, u8 value)
{
    lbl_8064D4AC[index].fieldD4 = lbl_8064D4D8;
    fn_801C7580(&lbl_8064D4AC[index], value);
}
