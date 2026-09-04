typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct PoolEntry {
    void* object;
    void* aux;
    u8 pad08[0x1C];
    u32 fields[5];
    u16 object_hi;
    u16 object_lo;
    u8 pad3c[0x12];
    u16 aux_hi;
    u16 aux_lo;
    u8 pad52[0x92];
    u8 ff[4];
    u32 buffer;
    u8 zero[3];
    u8 padEF;
    u8 padF0[4];
} PoolEntry;

typedef struct ArenaEntry {
    void* small;
    u32 fields[9];
    void* arena;
    void* slices[7];
    u8 pad48[8];
    u8 flag;
    u8 pad51[0x6B];
} ArenaEntry;

extern u8 lbl_8064D4E5;
extern u8 lbl_8064D4E4;
extern void* lbl_8064D478;
extern void* lbl_8064D498;
extern void* lbl_8064D4A4;
extern PoolEntry* lbl_8064D4AC;
extern u8* lbl_8064D4A8;
extern void* lbl_8064D4A0;
extern ArenaEntry lbl_80628CB0[];

extern void* fn_801CDA04(void);
extern void* fn_801CE330(u32);
extern void* memset(void*, int, u32);
extern void DCFlushRange(void*, u32);
extern void DCFlushRangeNoSync(void*, u32);
extern void DCInvalidateRange(void*, u32);
extern void fn_8020B7D8(void*);
extern void fn_801C458C(int, int, int);
extern void fn_801C4478(void);

int fn_801C40D4(u8 count, u8 arena_count, int enable)
{
    int i;
    u32 offset;
    u8* aux;
    ArenaEntry* entry;

    lbl_8064D4E5 = count;
    lbl_8064D4E4 = arena_count;
    lbl_8064D478 = fn_801CDA04();
    lbl_8064D498 = fn_801CE330(0x800);
    if (lbl_8064D498 == 0)
        return 0;
    lbl_8064D4A4 = fn_801CE330(0x280);
    if (lbl_8064D4A4 == 0)
        return 0;
    memset(lbl_8064D4A4, 0, 0x280);
    DCFlushRange(lbl_8064D4A4, 0x280);
    lbl_8064D4AC = fn_801CE330(lbl_8064D4E5 * 0xF4);
    if (lbl_8064D4AC == 0)
        return 0;
    lbl_8064D4A8 = fn_801CE330(lbl_8064D4E5 << 6);
    if (lbl_8064D4A8 == 0)
        return 0;
    DCInvalidateRange(lbl_8064D4A8, lbl_8064D4E5 << 6);

    aux = lbl_8064D4A8;
    for (i = 0, offset = 0; i < lbl_8064D4E5; i++, offset += 0xF4) {
        PoolEntry* p = (PoolEntry*)((u8*)lbl_8064D4AC + offset);
        p->zero[0] = 0;
        p->zero[1] = 0;
        p->zero[2] = 0;
        p->ff[0] = 0xFF;
        p->ff[1] = 0xFF;
        p->ff[2] = 0xFF;
        p->ff[3] = 0xFF;
        p->object = fn_801CE330(0xBC);
        memset(p->object, 0, 0xBC);
        p->aux = fn_801CE330(0x80);
        p->object_hi = (u32)p->object >> 16;
        p->object_lo = (u32)p->object;
        p->aux_hi = (u32)p->aux >> 16;
        p->aux_lo = (u32)p->aux;
        p->buffer = (u32)aux;
        aux += 0x40;
        fn_8020B7D8(p->object);
        p->fields[0] = 0;
        p->fields[1] = 0;
        p->fields[2] = 0;
        p->fields[3] = 0;
        p->fields[4] = 0;
    }

    entry = lbl_80628CB0;
    for (i = 0; i < lbl_8064D4E4; i++, entry++) {
        entry->flag = 0;
        entry->small = fn_801CE330(0x36);
        if (entry->small == 0)
            return 0;
        entry->arena = fn_801CE330(0x3C00);
        if (entry->arena == 0)
            return 0;
        memset(entry->arena, 0, 0x3C00);
        DCFlushRangeNoSync(entry->arena, 0x3C00);
        entry->slices[0] = (u8*)entry->arena + 0x780;
        entry->slices[1] = (u8*)entry->slices[0] + 0x780;
        entry->slices[2] = (u8*)entry->slices[1] + 0x780;
        entry->slices[3] = (u8*)entry->slices[2] + 0x780;
        entry->slices[4] = (u8*)entry->slices[3] + 0x780;
        entry->slices[5] = (u8*)entry->slices[4] + 0x780;
        entry->slices[6] = (u8*)entry->slices[5] + 0x780;
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
    }
    fn_801C458C(0, 1, enable != 0);
    lbl_8064D4A0 = fn_801CE330(0x100);
    if (lbl_8064D4A0 == 0)
        return 0;
    fn_801C4478();
    return 1;
}
