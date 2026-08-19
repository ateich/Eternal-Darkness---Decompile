typedef unsigned int u32;

typedef struct Entry {
    u32 value;
    u32 data;
    u32 flags;
} Entry;

typedef struct Object Object;
typedef void (*Callback)(Object*, int);

struct Object {
    u32 pad;
    Entry entries[32];
    int count;
    u32 cached_flags;
    u32 field_18C;
    u32 field_190;
    Callback callback;
};

extern void* memset(void*, int, unsigned int);
extern int fn_80157FE0(Object*, u32, int);
extern void fn_80157FA8(Object*);
extern int fn_80158514(Object*, int);

void fn_80158038(Object* object, int value)
{
    int index;
    u32 flags;

    index = fn_80158514(object, value);
    if (index >= 0) {
        flags = object->entries[index].flags;
        if (flags != 0) {
            int dependent;
            while ((dependent = fn_80157FE0(object, flags, 0)) >= 0) {
                fn_80158038(object, dependent);
            }
            index = fn_80158514(object, value);
        }
        for (; index < 31; index++) {
            object->entries[index] = object->entries[index + 1];
        }
        memset(&object->entries[31], 0, sizeof(Entry));
        object->count--;
        if (object->callback != 0) {
            object->callback(object, value);
        }
    }
    fn_80157FA8(object);
}
