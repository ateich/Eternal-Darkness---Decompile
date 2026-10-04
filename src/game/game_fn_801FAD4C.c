typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Header {
    u32 count;
    u32 index;
    int argument;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    u16 version;
    u8 pad1E[0x22];
} Header;

typedef struct Record {
    u16 flags;
    u8 first_index;
    u8 second_index;
    u8 pad04[0xC];
} Record;

typedef struct MotionState {
    u8 pad00[0x70];
    struct MotionState* source;
    struct MotionState* next;
    u8 pad78[0x10];
} MotionState;

typedef struct Entry {
    u8 data[0x14];
} Entry;

extern u32 lbl_8064D7BC;
extern u32 lbl_8064C3A8;
extern u32 lbl_8064C3A0;
extern u32 lbl_8064D798;
extern u32 lbl_8064C3A4;
extern u32 lbl_8064D79C;
extern int lbl_8064D18C;
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_801FBB84(Record*, Entry*);
extern u16 fn_801FB6A4(void*, MotionState*, int, int);
extern void fn_801F85A4(void);
extern void fn_801FA354(void);

static MotionState first[12] = {0};
static MotionState second[12] = {0};
static MotionState current_first = {0};
static MotionState current_second = {0};
static Entry entries[5] = {0};

static inline void link_pairs(void)
{
    int i;

    for (i = 0; i < 12; i++) {
        second[i].next = &first[i];
        first[i].next = 0;
    }
}

u32 fn_801FAD4C(void* input)
{
    Header header;
    Record record;
    Entry* entry;
    int i;
    u16 offset;
    int valid = 1;

    memcpy(&header, input, 0x40);
    offset = 0x40;
    if (header.version != lbl_8064D18C) {
        valid = 0;
    }
    if (valid) {
        lbl_8064D7BC = header.count;
        lbl_8064C3A8 = header.index;
        lbl_8064C3A0 = header.field0C;
        lbl_8064D798 = header.field10;
        lbl_8064C3A4 = header.field14;
        lbl_8064D79C = header.field18;
    }

    entry = entries;
    for (i = 0; i < (int)lbl_8064D7BC; entry++, i++) {
        memcpy(&record, (u8*)input + offset, 0x10);
        offset += 0x10;
        if (valid) {
            fn_801FBB84(&record, entry);
        }
        if (record.flags & 1) {
            offset += fn_801FB6A4((u8*)input + offset,
                                  &second[record.first_index], 0, valid);
        }
        if (record.flags & 2) {
            offset += fn_801FB6A4((u8*)input + offset,
                                  &first[record.second_index], 1, valid);
        }
    }

    offset += fn_801FB6A4((u8*)input + offset, &current_first, 0, valid);
    current_first.source = &second[lbl_8064C3A8];
    current_first.next = &current_second;
    offset += fn_801FB6A4((u8*)input + offset, &second[lbl_8064C3A8], 0,
                          valid);
    offset += fn_801FB6A4((u8*)input + offset, &current_second, 1, valid);
    current_second.source = &first[lbl_8064C3A8];
    current_second.next = 0;
    offset += fn_801FB6A4((u8*)input + offset, &first[lbl_8064C3A8], 1,
                          valid);

    link_pairs();
    if (header.argument != 0) {
        fn_801F85A4();
        fn_801FA354();
    }
    return (u16)(offset + 0x1F) & ~0x1F;
}
