typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Header {
    u32 field00;
    u32 field04;
    u32 argument;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    u16 field1C;
    u8 pad1E[0x22];
} Header;

typedef struct Record {
    u16 flags;
    u8 first_index;
    u8 second_index;
    u8 pad04[0xC];
} Record;

extern u32 lbl_8064D7BC;
extern u32 lbl_8064C3A8;
extern u32 lbl_8064C3A0;
extern u32 lbl_8064D798;
extern u32 lbl_8064C3A4;
extern u32 lbl_8064D79C;
extern u32 lbl_8064D18C;
typedef struct BlockGlobals {
    u8 first[0x660];
    u8 second[0x660];
    u8 primary[0x88];
    u8 secondary[0x88];
    u8 entries[1];
} BlockGlobals;
extern BlockGlobals lbl_8063C6B8;
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_801FBAC8(void*, Record*);
extern u16 fn_801FB3B4(void*, void*, int);

u32 fn_801FABA4(void* output, int argument)
{
    Header header;
    Record record;
    u8* entry;
    int i;
    u16 offset;
    BlockGlobals* const globals = &lbl_8063C6B8;

    header.field00 = lbl_8064D7BC;
    header.field04 = lbl_8064C3A8;
    header.argument = argument;
    header.field0C = lbl_8064C3A0;
    header.field10 = lbl_8064D798;
    header.field14 = lbl_8064C3A4;
    header.field18 = lbl_8064D79C;
    header.field1C = lbl_8064D18C;
    memcpy(output, &header, 0x40);
    for (entry = globals->entries, i = 0, offset = 0x40;
         i < (int)lbl_8064D7BC; entry += 0x14, i++) {
        fn_801FBAC8(entry, &record);
        memcpy((u8*)output + offset, &record, 0x10);
        offset += 0x10;
        if (record.flags & 1) {
            u8* base = globals->second;
            offset += fn_801FB3B4((u8*)output + offset,
                                  base + record.first_index * 0x88, 0);
        }
        if (record.flags & 2) {
            u8* base = globals->first;
            offset += fn_801FB3B4((u8*)output + offset,
                                  base + record.second_index * 0x88, 1);
        }
    }

    offset += fn_801FB3B4((u8*)output + offset, globals->primary, 0);
    {
        u8* base = globals->second;
        base += lbl_8064C3A8 * 0x88;
        offset += fn_801FB3B4((u8*)output + offset, base, 0);
    }
    offset += fn_801FB3B4((u8*)output + offset, globals->secondary, 1);
    {
        u8* base = globals->first;
        offset += fn_801FB3B4((u8*)output + offset,
                              base + lbl_8064C3A8 * 0x88, 1);
    }
    /* The packed size wraps to 16 bits before alignment. */
    return (u16)(offset + 0x1F) & ~0x1F;
}
