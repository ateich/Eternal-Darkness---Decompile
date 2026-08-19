typedef struct Object {
    char _pad00[0x60];
    int allocation_size;
} Object;

typedef struct Entry {
    char _pad00[0xE];
    short count;
} Entry;

extern char lbl_8064BA80;
extern void* fn_8016B5CC(Object*, Entry*, unsigned int, char*, int);

void fn_80161380(Object* object, Entry* entry)
{
    object->allocation_size -= ((entry->count - 1) << 4) + 0x20;
    fn_8016B5CC(object, entry, 0, &lbl_8064BA80, 90);
}
