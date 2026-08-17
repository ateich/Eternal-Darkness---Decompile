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

typedef struct FlagSlot {
    u16 flags;
    u8 pad[6];
} FlagSlot;

typedef struct Object {
    u8 pad[0x3C];
    void* countSource;
    u8 pad40[0x140];
    FlagSlot flags[24];
    Entry** entries;
} Object;

#pragma use_lmw_stmw on

extern int fn_8012BE8C(void*);
extern void fn_80125ECC(void*);

void fn_8012FBF4(Object* object)
{
    int count = fn_8012BE8C(object->countSource);
    int i;

    fn_80125ECC(object);
    for (i = 0; i < count; i++) {
        Entry* entry = object->entries[i];
        if (entry != 0) {
            int j;
            List* list = entry->list;
            for (j = 0; j < list->count; j++) {
                list->values[j] &= 0x7FFF;
                object->flags[list->values[j]].flags |= 2;
            }
        }
    }
}
