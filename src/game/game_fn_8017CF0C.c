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

extern BufferState lbl_80606300;
extern BufferState lbl_8060630C;
extern void fn_8017CFC0(Entry**);

void fn_8017CF0C(void)
{
    int count;
    int i;
    Manager* manager;

    manager = lbl_80606300.managers;
    count = lbl_8060630C.manager_count;
    for (i = 0; i < count; i++) {
        fn_8017CFC0(&manager->entries);
        manager++;
    }
}
