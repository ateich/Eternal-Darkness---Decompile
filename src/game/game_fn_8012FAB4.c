typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u8 pad[8];
    u16 flags;
    u8 padA[0x25];
    u8 value2F;
} Entry;

typedef struct Object {
    u8 pad[0x240];
    Entry** entries;
} Object;

extern void fn_80125ECC(void *);

int fn_8012FAB4(Object* object, int index)
{
    Entry* entry;

    if (object != 0) {
        fn_80125ECC(object);
        entry = object->entries[index];
        if (entry != 0) {
            int result = 0;
            if (entry->flags & 4) {
                if (entry->value2F == 0) {
                    result = 1;
                }
            }
            return result;
        }
    }
    return 0;
}
