typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u8 pad[8];
    u16 flags;
} Entry;

typedef struct Object {
    u8 pad[0x240];
    Entry** entries;
} Object;

extern void fn_80125ECC(void *);

int fn_8012FA54(Object* object, int index)
{
    Entry* entry;

    if (object != 0) {
        fn_80125ECC(object);
        entry = object->entries[index];
        if (entry != 0) {
            return entry->flags & 1;
        }
    }
    return 0;
}
