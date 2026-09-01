typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Source {
    u8 padding[12];
    u32 size;
} Source;

typedef struct Entry {
    u8 state;
    u8 value1;
    u8 value2;
    u8 value3;
    u8 padding04[12];
    Source* source;
    u8 padding14[64];
    u32 half_size;
    u32 source_size;
    u8* buffer;
    u32 buffer_size;
    u32 second_size;
    u8 enabled;
    u8 value69;
    u8 value6A;
    u8 padding6B;
    u32 value6C;
    u32 value70;
    u32 value74;
    u32 value78;
} Entry;

extern void* memset(void*, int, unsigned long);

u32 fn_801ADE0C(Entry* entry, Source* source, u8 value1, u8 value2,
                u8 value3, u8 value69, u8 value6A)
{
    u32 result;
    u32 source_size;
    u32 half_size;

    entry->source = source;
    entry->value69 = value69;
    entry->value6A = value6A;
    entry->value1 = value1;
    entry->value2 = value2;
    entry->value3 = value3;
    entry->value6C = 1;
    entry->value70 = 0;
    entry->value78 = 0;
    entry->value74 = 1;
    entry->enabled = 1;
    entry->buffer_size = 0xB2C0;
    entry->second_size = (entry->buffer_size >> 3) * 14;
    if (entry->buffer_size > 0xB2C0) {
        entry->buffer_size = 0xB2C0;
    }

    half_size = entry->buffer_size >> 1;
    entry->half_size = half_size;
    entry->source_size = entry->source->size;
    source_size = entry->source_size;
    if (source_size < half_size) {
        result = source_size;
        memset(entry->buffer + source_size, 0, half_size - source_size);
    } else {
        result = half_size;
    }

    entry->state = 2;
    return result;
}
