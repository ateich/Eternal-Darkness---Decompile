typedef struct Entry {
    signed char state;
    unsigned char pad[3];
    void* data;
    struct Entry* next;
} Entry;

Entry* fn_8017D078(Entry* entry)
{
    Entry* next = 0;

    if (entry != 0) {
        next = entry->next;
        entry->next = 0;
    }
    return next;
}
