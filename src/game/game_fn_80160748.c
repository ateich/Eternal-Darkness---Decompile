typedef struct Entry {
    long long first;
    long long second;
} Entry;

typedef struct Object {
    Entry* current;
    Entry* allocation;
    Entry* end;
    int count;
} Object;

extern void fn_8016057C(Object*, int);

void fn_80160748(Object* object, Entry* allocation)
{
    int count = object->current - allocation;
    Entry* entry = allocation + count;

    for (;;) {
        if (count == 0)
            break;
        entry[1] = entry[0];
        count--;
        entry--;
    }

    if (object->current == object->end)
        fn_8016057C(object, 1);
    object->current++;
}
