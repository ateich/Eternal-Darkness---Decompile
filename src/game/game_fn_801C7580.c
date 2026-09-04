typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry Entry;
struct Entry {
    unsigned char pad00[0xC];
    Entry* next;
    Entry* previous;
    unsigned char pad14[0x10];
    u32 flags;
    unsigned char pad28[0xC4];
    u8 active;
    u8 state;
    u8 pending;
    u8 group;
};

extern Entry* lbl_80628CB0[];
void fn_801C7624(Entry* entry);

void fn_801C7580(Entry* entry, u8 group)
{
    Entry** head;

    if (entry->active != 0) {
        fn_801C7624(entry);
        entry->flags |= 0x20;
    }

    entry->state = 0;
    head = lbl_80628CB0 + group * 47;
    entry->next = head[18];
    if (entry->next != 0) {
        entry->next->previous = entry;
    }
    entry->previous = 0;
    head[18] = entry;
    entry->pending = 0;
    entry->active = 1;
    entry->group = group;
}
