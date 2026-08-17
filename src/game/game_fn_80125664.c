typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Record {
    u32 first;
    u8 pad4[0x114];
    u32 source;
    u8 pad11C[4];
    u32 second;
} Record;

typedef struct Header {
    u8 pad0[0x10];
    u32 self_offset;
    u16 count;
    u8 pad16[2];
    Record* records;
    u8 pad1C[4];
    void* field20;
    u8 pad24[4];
    void* field28;
} Header;

typedef struct Buffer {
    u8 pad0[0x10];
    u32 count;
} Buffer;

extern s32 fn_80125D1C(Header*);

Header* fn_80125664(Header* header, Buffer* buffer)
{
    u32 buffer_offset = 0;
    s32 i;

    if (!fn_80125D1C(header))
        return header;

    if (buffer != 0) {
        buffer_offset = ((buffer->count * 16 + 31) & ~31) + 32;
    }

    header->self_offset = (u32)header + header->self_offset;
    if (header->records != 0)
        header->records = (Record*)((u8*)header + (u32)header->records);
    if (header->field20 != 0)
        header->field20 = (u8*)header + (u32)header->field20;
    if (header->field28 != 0)
        header->field28 = (u8*)header + (u32)header->field28;

    for (i = 0; i < header->count; i++) {
        Record* record = &header->records[i];
        u32 source = record->source;
        record->first = 0;
        record->second = 0;
        if (source & 0x40000000)
            record->source = (u32)((source & 0x3FFFFFFF) +
                                    (u8*)buffer + buffer_offset);
        else
            record->source = (u32)((u8*)header + source);
    }
    return header;
}
