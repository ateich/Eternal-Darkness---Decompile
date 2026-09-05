typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct CacheEntry {
    u8 bytes[0x20];
    u16 value;
    u8 tail[2];
} CacheEntry;

extern u32 lbl_80253370[];
extern u32 lbl_80630770[][16];
extern CacheEntry lbl_8061A9C4[][4];
extern u16 fn_801CB4F8(u8*, u8*, u8, u8);

u16 fn_801CBCE0(u8 voice, u8 channel, u8 entry, u8 row)
{
    u32 pending;
    u32 mask = lbl_80253370[(u8)channel];
    pending = !!(mask & lbl_80630770[(u8)row][(u8)entry]);

    if (pending) {
        lbl_80630770[(u8)row][(u8)entry] &= ~mask;
    }
    if (!pending) {
        return lbl_8061A9C4[(u8)voice][(u8)channel].value;
    }
    return fn_801CB4F8(0, (u8*)&lbl_8061A9C4[(u8)voice][(u8)channel], entry,
                       row);
}
