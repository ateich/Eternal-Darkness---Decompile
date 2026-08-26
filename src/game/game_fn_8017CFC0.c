typedef signed char s8;

typedef struct Entry {
    s8 state;
    unsigned char pad[3];
    void* data;
    struct Entry* next;
} Entry;

extern Entry* fn_8017D064(Entry*, Entry*);
extern Entry* fn_8017D098(Entry*, Entry*, Entry*);

void fn_8017CFC0(Entry** entries)
{
    Entry* current = entries[1];
    Entry* first;
    Entry* last = entries[3];
    Entry* entry;
    Entry* previous = 0;

    first = entries[2];
    entry = entries[2];

    while (entry != 0) {
        if (entry->state == 0) {
            first = fn_8017D098(first, previous, last);
            current = fn_8017D064(current, last);
            current = entry;
            last = previous;
            break;
        }
        entry->state--;
        previous = entry;
        entry = entry->next;
    }

    entries[1] = current;
    entries[2] = first;
    entries[3] = last;
}
