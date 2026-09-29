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

typedef struct BufferState {
    Manager* managers;
    Entry* entries;
    u16 manager_count;
    u16 entry_count;
} BufferState;

extern BufferState lbl_8060630C;
extern void* memset(void*, int, u32);
extern void fn_8017CF74(Manager*);

void* fn_8017CCD8(void* data, u32 size, u16 count)
{
    Manager* manager = lbl_8060630C.managers;

    memset(data, 0, size * count);
    manager->data = data;
    manager->size = size;
    manager->count = count;
    manager->entries = lbl_8060630C.entries;
    manager->current = lbl_8060630C.entries;
    manager->first = 0;
    manager->last = 0;
    fn_8017CF74(manager);

    lbl_8060630C.managers++;
    lbl_8060630C.manager_count++;
    lbl_8060630C.entries += count;
    lbl_8060630C.entry_count += count;
    return manager;
}
