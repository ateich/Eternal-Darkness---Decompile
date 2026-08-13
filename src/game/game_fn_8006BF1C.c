typedef signed int s32;
typedef unsigned short u16;

typedef struct Entry {
    unsigned char bytes[0x2C];
    void *name;
    unsigned char tail[0x44];
} Entry;

typedef struct EntryList {
    unsigned char bytes[0x10];
    u16 count;
    unsigned char pad[2];
    Entry *entries;
} EntryList;

extern EntryList *fn_8015C390(s32 kind);
extern void *fn_801E741C(const char *name);
extern s32 fn_8013B8C0(void *object, Entry *entry);

s32 fn_8006BF1C(void *object, const char *name)
{
    EntryList *list;
    void *resolved;
    s32 i;
    Entry *entry;

    list = fn_8015C390(2);
    resolved = fn_801E741C(name);
    if (list != 0) {
        entry = list->entries;
        for (i = 0; i < list->count; i++, entry++) {
            if (entry->name == resolved && fn_8013B8C0(object, entry) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
