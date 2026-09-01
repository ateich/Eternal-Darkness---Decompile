typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 padding00[96];
    u32 chunk_size;
    u32 buffer_size;
    u8 half;
    u8 padding69[7];
    int stopped;
    u8 padding74[8];
    u32 buffered;
    u32 consumed;
} Entry;

extern void fn_801AE368(Entry*);
extern int fn_801AE3C8(Entry*);

u32 fn_801AE530(u32 unused1, u32 offset, u32 unused3, u32 count,
                Entry* entry)
{
    u32 amount;

    if (entry->stopped != 0) {
        fn_801AE368(entry);
        return 0;
    }

    if ((entry->buffered = offset + count) < (entry->buffer_size >> 1)) {
        return 0;
    }

    if (fn_801AE3C8(entry) == 0) {
        return 0;
    }

    entry->consumed += entry->buffer_size >> 1;
    amount = entry->buffer_size >> 1;
    entry->buffered -= amount;
    return entry->buffer_size >> 1;
}
