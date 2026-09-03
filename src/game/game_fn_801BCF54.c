typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Table {
    void* entries;
    u32 unused;
    u16 count;
    u16 padding;
} Table;

typedef struct FoundEntry {
    u16 id;
    u16 type;
    u32 unused4;
    u32 value8;
    u32 payload[4];
    u32 adjustment;
} FoundEntry;

typedef struct Result {
    u32 value0;
    u32 value4;
    u32 value8;
    u32 valueC;
    u32 value10;
    u32 value14;
    u32 value18;
    u8 value1C;
} Result;

extern u8 lbl_8061C748[];
extern u16 lbl_8064D3F0;
extern FoundEntry* lbl_8064D410;
extern u32* lbl_8064D414;
extern int fn_801BCF44(void*, void*);
extern void* fn_801CC370(void*, void*, unsigned int, unsigned int,
                        int (*)(void*, void*));

int fn_801BCF54(u16 id, Result* output)
{
    u8* base = lbl_8061C748;
    int i;
    Table* table;

    i = 0;
    table = (Table*)(base + i * 12);
    *(u16*)(base + 0xA600) = id;
    for (; i < lbl_8064D3F0; i++) {
        if ((lbl_8064D410 = fn_801CC370(base + 0xA600, table->entries,
                                        table->count, 0x20, fn_801BCF44)) != 0 &&
            lbl_8064D410->type != 0xFFFF) {
            lbl_8064D414 = lbl_8064D410->payload;
            output->value0 = lbl_8064D414[0];
            output->value4 = lbl_8064D410->value8;
            output->valueC = 0;
            output->value14 = lbl_8064D414[2];
            output->value10 = lbl_8064D414[1] & 0x00FFFFFF;
            output->value18 = lbl_8064D414[3];
            output->value1C = lbl_8064D414[1] >> 24;
            if (lbl_8064D410->adjustment != 0) {
                output->value8 = lbl_8064D410->adjustment +
                                 (u32)((Table*)base)[i].entries;
            }
            return 0;
        }
        table++;
    }
    return -1;
}
