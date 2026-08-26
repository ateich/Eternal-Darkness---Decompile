typedef struct Entry {
    signed char state;
    unsigned char pad[3];
    void* data;
    struct Entry* next;
} Entry;

extern Entry* fn_8017D078(Entry*);

Entry* fn_8017D098(Entry* first, Entry* previous, Entry* last)
{
    if (previous != 0) {
        previous->next = last->next;
        last->next = 0;
    } else {
        first = fn_8017D078(last);
    }
    return first;
}
