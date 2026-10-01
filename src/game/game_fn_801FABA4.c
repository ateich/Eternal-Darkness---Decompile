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

typedef struct MotionState {
    u8 pad00[0x70];
    struct MotionState* source;
    u8 pad74[0x14];
} MotionState;

typedef struct Entry {
    u8 data[0x14];
} Entry;

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
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_801FBAC8(Entry*, Record*);
extern u16 fn_801FB3B4(void*, MotionState*, int);

static MotionState first[12] = {0};
static MotionState second[12] = {0};
static MotionState current_first = {0};
static MotionState current_second = {0};
static Entry entries[5] = {0};

u32 fn_801FABA4(u8* output, int argument)
{
    Header header;
    Record record;
    Entry* entry;
    int i;
    u16 offset;

    header.field00 = lbl_8064D7BC;
    header.field04 = lbl_8064C3A8;
    header.argument = argument;
    header.field0C = lbl_8064C3A0;
    header.field10 = lbl_8064D798;
    header.field14 = lbl_8064C3A4;
    header.field18 = lbl_8064D79C;
    header.field1C = lbl_8064D18C;
    memcpy(output, &header, 0x40);
    for (entry = entries, i = 0, offset = 0x40; i < (int)lbl_8064D7BC; entry++, i++) {
        fn_801FBAC8(entry, &record);
        memcpy(output + offset, &record, 0x10);
        offset += 0x10;
        if (record.flags & 1) {
            offset += fn_801FB3B4(output + offset, &second[record.first_index], 0);
        }
        if (record.flags & 2) {
            offset += fn_801FB3B4(output + offset, &first[record.second_index], 1);
        }
    }

    offset += fn_801FB3B4(output + offset, &current_first, 0);
    offset += fn_801FB3B4(output + offset, &second[lbl_8064C3A8], 0);
    offset += fn_801FB3B4(output + offset, &current_second, 1);
    offset += fn_801FB3B4(output + offset, &first[lbl_8064C3A8], 1);
    return (u16)(offset + 0x1F) & ~0x1F;
}
