typedef signed char s8;
typedef unsigned int u32;

typedef struct Entry {
    s8 state;
    s8 pad[3];
    void* data;
    struct Entry* next;
} Entry;

typedef struct Manager {
    void* data;
    unsigned short count;
    unsigned short pad;
    u32 size;
    Entry* entries;
    Entry* current;
    Entry* first;
    Entry* last;
} Manager;

extern Entry* fn_8017D064(Entry*, Entry*);

void fn_8017CE74(Manager* manager, void* data)
{
    int was_empty = 0;
    Entry* entry;
    Entry* first;

    if (data != 0) {
        first = manager->first;
        if (first == 0) {
            was_empty = 1;
        }
        entry = &manager->entries[((u32)data - (u32)manager->data) / manager->size];
        if (entry->state == -1) {
            entry->state = 0;
            manager->first = fn_8017D064(first, entry);
            if (was_empty != 0) {
                manager->last = manager->first;
            }
        }
    }
}
