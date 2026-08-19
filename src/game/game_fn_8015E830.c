typedef unsigned int u32;

typedef struct StreamEntry {
    unsigned char pad0[0x10];
    u32 start;
    u32 size;
} StreamEntry;

extern int lbl_8064D178;
extern u32 lbl_8064D1B4;
extern StreamEntry lbl_805B6F80[];

int fn_8015E830(u32 value)
{
    if (value < lbl_805B6F80[lbl_8064D178].start ||
        value >= lbl_8064D1B4)
        return 0;
    return 1;
}
