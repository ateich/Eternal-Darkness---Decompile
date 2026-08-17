typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Queue {
    void* callbacks[14];
    u32 values[14];
    u32 kinds[14];
    u8 padA8[0x5A];
    u8 flags[14];
} Queue;

typedef struct Entry {
    u32 unknown0;
    int value;
    u32 unknown8;
} Entry;

extern Queue* fn_80128E30(void*);
extern void fn_801292E0(void*, int*, Entry**);

int fn_801288DC(void* owner, int value)
{
    Entry* entries;
    int count;
    Queue* queue;
    int removed = 0;
    int i;

    queue = fn_80128E30(owner);
    fn_801292E0(owner, &count, &entries);
    for (i = 0; i < count; i++) {
        if (value == entries[i].value) {
            queue->flags[i] = 0;
            queue->callbacks[i] = 0;
            queue->values[i] = 0;
            queue->kinds[i] = 0;
            removed++;
        }
    }
    return removed;
}
