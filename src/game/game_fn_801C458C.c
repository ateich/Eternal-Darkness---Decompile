typedef unsigned char u8;
typedef unsigned int u32;

typedef struct ArenaEntry {
    void* small;
    u32 fields[9];
    void* arena;
    void* slices[7];
    u32 value48;
    u32 value4C;
    u8 flag;
    u8 mode;
    u8 state;
    u8 pad53;
    u32 value54;
    u8 pad58[0x54];
    u32 valueAC;
    u32 valueB0;
    u8 padB4[8];
} ArenaEntry;

extern ArenaEntry lbl_80628CB0[];
extern void* memset(void*, int, u32);
extern void DCFlushRangeNoSync(void*, u32);

void fn_801C458C(u8 index, u8 mode, u32 value)
{
    ArenaEntry* base;
    void** member;
    u32 offset;
    ArenaEntry* entry;

    base = lbl_80628CB0;
    offset = index * sizeof(ArenaEntry);
    member = (void**)((u8*)base + offset);
    member += 10;
    memset(*member, 0, 0x3C00);
    DCFlushRangeNoSync(*member, 0x3C00);
    entry = (ArenaEntry*)((u8*)base + offset);
    memset(entry->small, 0, 0x36);
    entry->fields[2] = 0;
    entry->fields[1] = 0;
    entry->fields[0] = 0;
    entry->fields[5] = 0;
    entry->fields[4] = 0;
    entry->fields[3] = 0;
    entry->fields[8] = 0;
    entry->fields[7] = 0;
    entry->fields[6] = 0;
    DCFlushRangeNoSync(entry->small, 0x36);
    member = (void**)((u8*)entry + 0x30);
    memset(*member, 0, 0x780);
    DCFlushRangeNoSync(*member, 0x780);
    member = (void**)((u8*)entry + 0x3C);
    memset(*member, 0, 0x780);
    DCFlushRangeNoSync(*member, 0x780);
    entry->value48 = 0;
    entry->value4C = 0;
    entry->flag = 1;
    entry->mode = mode;
    entry->state = 0;
    entry->value54 = value;
    entry->valueB0 = 0;
    entry->valueAC = 0;
}
