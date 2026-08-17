typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Entry {
    u32 clear;
    unsigned char pad4[0x114];
    u32 source;
    u32 size;
    u32 state;
} Entry;

typedef struct Header {
    unsigned char pad0[0x14];
    u16 count;
    unsigned char pad16[2];
    u32 entries;
} Header;

extern u32 lbl_80649E5C;
extern void* fn_80138A6C(u32);
extern u32 fn_8015E7A0(void);
extern u32 fn_8015E7C8(u32);
extern void fn_8015D7D4(u32, void*, void*, u32, int);
extern void* memcpy(void*, const void*, u32);

Header* fn_80139B1C(unsigned char* base, int unused, u32* offset, void* source_base,
                    int mode)
{
    Header* input = (Header*)(base + *offset);
    u32 header_size = input->count * 0x128 + 0x48;
    Header* result = fn_80138A6C(header_size);
    u32 total = 0;
    u32 checkpoint = fn_8015E7A0();
    Entry* entry;
    int i;

    memcpy(result, input, header_size);
    result->entries += (u32)result;
    entry = (Entry*)result->entries;
    for (i = 0; i < result->count; i++, entry++) {
        u32 size = (entry->size + 31) & ~31;
        u32 position = fn_8015E7C8(size);
        total += size;
        if (checkpoint <= position) {
            fn_8015D7D4(position, source_base,
                        base + *offset + entry->source, size, mode);
        }
        entry->source = position;
        entry->clear = 0;
        entry->state = 0;
    }
    lbl_80649E5C += total;
    return result;
}
