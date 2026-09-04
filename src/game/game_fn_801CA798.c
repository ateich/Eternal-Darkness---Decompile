typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_80630770[][16];

void fn_801CA798(u32 entry, u32 row, u32 flags)
{
    lbl_80630770[(u8)row][(u8)entry] |= flags;
}
