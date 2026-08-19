typedef struct Entry {
    int values[8];
    short counts[4];
    struct Entry* next;
    int tail[6];
} Entry;

typedef struct Object {
    char _pad00[0x20];
    Entry* entries;
} Object;

extern char lbl_8064BA80;
extern void* fn_8016B5CC(Object*, int, unsigned int, char*, int);

void fn_80161164(Object* object)
{
    Entry* entry = fn_8016B5CC(object, 0, 0x44, &lbl_8064BA80, 33);
    int i;

    for (i = 0; i < 8; i++)
        entry->values[i] = 0;
    for (i = 0; i < 4; i++)
        entry->counts[i] = 0;
    for (i = 0; i < 6; i++)
        entry->tail[i] = 0;
    entry->next = object->entries;
    object->entries = entry;
}
