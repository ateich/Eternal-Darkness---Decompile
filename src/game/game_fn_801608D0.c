typedef struct Entry {
    double data[2];
} Entry;

typedef struct Object {
    Entry* current;
    char padding04[12];
    void* saved;
} Object;

typedef int (*Callback)(Object*);

typedef struct Packet {
    Callback callback;
    char padding04[10];
    short count;
    Entry entries[1];
} Packet;

extern void fn_8016057C(Object*, int);

Entry* fn_801608D0(Object* object, Packet* packet, void* replacement)
{
    int count;
    void* saved;
    int i;

    count = packet->count;
    saved = object->saved;
    object->saved = replacement;
    fn_8016057C(object, count + 20);

    for (i = 0; i < count; i++) {
        *object->current++ = packet->entries[i];
    }

    i = packet->callback(object);
    object->saved = saved;
    return object->current - i;
}
