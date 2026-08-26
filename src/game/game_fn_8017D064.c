typedef struct Entry {
    signed char state;
    unsigned char pad[3];
    void* data;
    struct Entry* next;
} Entry;

Entry* fn_8017D064(Entry* entry, Entry* tail)
{
    if (tail != 0) {
        tail->next = entry;
    }
    return tail;
}
