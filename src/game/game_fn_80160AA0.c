typedef struct Entry {
    int type;
    char padding04[4];
    void* value;
    char padding0C[4];
} Entry;

typedef struct Object {
    Entry* current;
} Object;

typedef void (*Callback)(Object*, Entry*, void*);

extern void fn_80160748(Object*, Entry*);
extern void fn_80160B18(Object*, Entry*, void*);

void fn_80160AA0(Object* object, void* value, int index, void* callback)
{
    Entry* entry;

    entry = object->current - index;
    fn_80160748(object, entry);
    entry->value = value;
    entry->type = 5;
    fn_80160B18(object, entry, callback);
}
