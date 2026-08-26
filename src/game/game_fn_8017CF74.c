typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 state;
    u8 pad[3];
    void* data;
    struct Entry* next;
} Entry;

typedef struct Manager {
    void* data;
    u16 count;
    u16 pad;
    u32 size;
    Entry* entries;
    Entry* current;
    Entry* first;
    Entry* last;
} Manager;

void fn_8017CF74(Manager* manager)
{
    int i;
    u8* data = manager->data;
    Entry* entry = manager->entries;

    for (i = 0; i < manager->count; i++) {
        entry->state = 0;
        entry->data = data;
        entry->next = entry + 1;
        entry++;
        data += manager->size;
    }
    (entry - 1)->next = 0;
}
