typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u32 size;
    u32 pad4;
    u32 index;
    u32 object_index;
} Entry;

typedef struct EntryList {
    u32 total_size;
    u32 pad4;
    Entry* entries;
    u32 padC;
    int count;
} EntryList;

typedef struct Runtime {
    unsigned char pad[0x60];
    unsigned char* objects;
} Runtime;

typedef struct Object {
    unsigned char pad0[0x3C];
    Runtime* runtime;
    unsigned char pad40[0x140];
    u16 flags[4];
    unsigned char pad188[0xCC];
    u32 state_flags;
} Object;

extern void fn_801ECF50(int mode);
extern EntryList* fn_801222A0(Runtime* runtime, int kind, int mode, int unused);
extern void fn_80122428(Runtime* runtime, EntryList* list, int kind, int mode, int unused);
extern int fn_80122538(Object* object, void* item);
extern int fn_80122C00(Object* object, void* item, u32 object_index, int arg,
                       int force, int extra, float first, float second);
extern void fn_8022B448(u32 offset, u32 size);

void fn_80122638(Object* object, int kind, int arg, int wanted, int force,
                 int extra, float first, float second)
{
    Runtime* runtime = object->runtime;
    int mode = 7;
    EntryList* list;
    Entry* entry;
    u32 offset;
    int i;

    if (object->state_flags & 0x00400000) {
        mode = 1;
    }
    fn_801ECF50(mode);
    list = fn_801222A0(runtime, kind, mode, 0);
    if (list->total_size == 0) {
        fn_80122428(runtime, list, kind, mode, 0);
    }

    entry = list->entries;
    offset = list->total_size;
    for (i = 0; i < list->count; i++, entry++) {
        if (entry->size != 0 &&
            (object->flags[entry->object_index] & 5) == 5) {
            void* item = runtime->objects + entry->index * 0x20;
            if (fn_80122538(object, item) == wanted || force != 0) {
                if (fn_80122C00(object, item, entry->object_index, arg, force,
                                extra, first, second)) {
                    fn_8022B448(offset, entry->size);
                }
            }
        }
        offset += entry->size;
    }
}
