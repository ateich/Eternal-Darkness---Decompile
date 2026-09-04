typedef unsigned char u8;

typedef struct Entry Entry;
struct Entry {
    unsigned char pad00[0xC];
    Entry* next;
    Entry* previous;
    Entry* next_secondary;
    unsigned char pad18[0xD4];
    u8 active;
    unsigned char padED[2];
    u8 group;
};

typedef struct Group {
    unsigned char pad00[0x48];
    Entry* head;
    Entry* secondary_head;
    unsigned char pad50[0x6C];
} Group;

extern Group lbl_80628CB0[];

void fn_801C7684(Entry* entry, u8 group)
{
    if (entry->active != 0) {
        if (entry->previous != 0) {
            entry->previous->next = entry->next;
        } else {
            lbl_80628CB0[entry->group].head = entry->next;
        }

        if (entry->next != 0) {
            entry->next->previous = entry->previous;
        }

        entry->next = lbl_80628CB0[group].head;
        if (entry->next != 0) {
            entry->next->previous = entry;
        }
        entry->previous = 0;
        lbl_80628CB0[group].head = entry;

        if (entry->active == 2) {
            entry->next_secondary = lbl_80628CB0[entry->group].secondary_head;
            lbl_80628CB0[entry->group].secondary_head = entry;
        }
    }
    entry->group = group;
}
