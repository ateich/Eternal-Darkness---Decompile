typedef unsigned char u8;
typedef unsigned short u16;

typedef struct List {
    u8 pad[6];
    u16 count;
    u16* values;
} List;

typedef struct Entry {
    u8 pad[4];
    List* list;
} Entry;

typedef struct Object {
    u8 pad[0x180];
    u16 flags[96];
    u8 pad240[0xC0];
    Entry** entries;
} Object;

extern void fn_80125ECC(void *);

void fn_8012FB50(Object* object, int index)
{
    Entry* entry;
    int i;

    fn_80125ECC(object);
    entry = object->entries[index];
    if (entry != 0) {
        List* list = entry->list;
        for (i = 0; i < list->count; i++) {
            u16 value = list->values[i];
            if (!(value & 0x8000)) {
                object->flags[value & 0x1FFF] |= 2;
            }
        }
    } else if (index == -1) {
        /* Retail accepts the sentinel as a no-op. */
    }
}
