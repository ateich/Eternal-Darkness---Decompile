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

extern void* memset(void*, int, u32);
extern Entry* fn_8017D078(Entry*);
extern void fn_8017CFC0(Entry**);

void* fn_8017CDB4(Manager* manager)
{
    void* result = 0;
    Entry* entry;

    if (manager != 0) {
        entry = manager->current;
        if (entry != 0) {
            manager->current = fn_8017D078(entry);
            entry->state = -1;
            result = entry->data;
            if (result != 0) {
                memset(result, 0, manager->size);
            }
        } else {
            fn_8017CFC0(&manager->entries);
            entry = manager->current;
            if (entry != 0) {
                manager->current = fn_8017D078(entry);
                entry->state = -1;
                result = entry->data;
                memset(result, 0, manager->size);
            }
        }
    }
    return result;
}
