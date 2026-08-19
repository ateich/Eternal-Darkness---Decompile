typedef union Entry {
    struct {
        int type;
        char padding04[4];
        void* value;
        short count;
        char padding0E[2];
    } fields;
    double copy[2];
} Entry;

typedef struct Holder {
    Entry* value;
    char padding04[28];
} Holder;

typedef void (*Callback)(struct Object*, Entry*, void*);

typedef struct TableEntry {
    char padding00[56];
    Entry* saved;
    char padding3C[4];
} TableEntry;

typedef struct Object {
    Entry* current;
    char padding04[4];
    Entry* end;
    char padding0C[60];
    TableEntry* table;
    char padding4C[24];
    Callback source;
} Object;

extern char lbl_8064BA68;
extern char lbl_8064BA70;

extern int fn_80167D2C(Entry*);
extern void fn_801603AC(Object*, Entry*, void*);
extern void fn_80160748(Object*, Entry*);
extern void fn_8016088C(Object*, void*, Callback, void*);
extern Entry* fn_801608D0(Object*, void*, void*);
extern Entry* fn_801697AC(Object*, void*, void*);
extern void fn_8016057C(Object*, int);
extern void fn_80161FA0(Object*);

void fn_80160B18(Object* object, Entry* entry, int amount)
{
    Callback callback_source;
    Entry* source;

    Holder holder;

    if (entry->fields.type != 5) {
        source = object->table[fn_80167D2C(entry)].saved;
        if (source == 0) {
            fn_801603AC(object, entry, &lbl_8064BA68);
        }
        fn_80160748(object, entry);
        entry->fields.value = source;
        entry->fields.type = 5;
    }

    source = entry->fields.value;
    holder.value = source;
    entry->fields.value = &holder;
    entry->fields.type = 6;
    callback_source = object->source;
    if (callback_source != 0) {
        fn_8016088C(object, entry, callback_source, &lbl_8064BA68);
    }

    if (source->fields.count != 0) {
        source = fn_801608D0(object, source, entry + 1);
    } else {
        source = fn_801697AC(object, source, entry + 1);
    }

    if (callback_source != 0) {
        fn_8016088C(object, entry, callback_source, &lbl_8064BA70);
    }

    if (amount == -1) {
        while (source < object->current) {
            *entry++ = *source++;
        }
        object->current = entry;
    } else {
        while (amount > 0 && source < object->current) {
            *entry++ = *source++;
            amount--;
        }
        object->current = entry;
        while (amount > 0) {
            object->current->fields.type = 1;
            if (object->current == object->end) {
                fn_8016057C(object, 1);
            }
            object->current++;
            amount--;
        }
    }
    fn_80161FA0(object);
}
