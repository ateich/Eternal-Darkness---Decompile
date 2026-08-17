typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SourceEntry {
    u32 offset;
    u32 pad;
    u16 id;
    unsigned char tail[6];
} SourceEntry;

typedef struct SourceHeader {
    unsigned char pad[0x10];
    u32 count;
    SourceEntry* entries;
} SourceHeader;

typedef struct Object {
    unsigned char pad[0x14];
    u16 count;
} Object;

typedef struct LoadedEntry {
    u32 id;
    Object* object;
    void* data;
} LoadedEntry;

typedef struct LoadedHeader {
    unsigned char pad[8];
    LoadedEntry* entries;
} LoadedHeader;

extern LoadedHeader* fn_80139C74(int, u32);
extern Object* fn_80125664(void*, SourceHeader*);
extern void* fn_80139CFC(u32);
extern void fn_8012B408(Object*, void*);

void fn_80138994(SourceHeader* header, int index)
{
    LoadedEntry* dest;
    SourceEntry* source;
    u32 i;

    if (header->entries != 0) {
        if (((u32)header->entries & 0x80000000) == 0) {
            header->entries = (SourceEntry*)((u32)header->entries +
                                             (u32)header);
        }
        dest = fn_80139C74(index, header->count)->entries;
        if (dest->data == 0) {
            source = header->entries;
            for (i = 0; i < header->count; i++, source++, dest++) {
                dest->object = fn_80125664((void*)(source->offset + (u32)header),
                                          header);
                dest->data = fn_80139CFC((u32)dest->object->count << 4);
                dest->id = source->id;
                fn_8012B408(dest->object, dest->data);
            }
        }
    }
}
