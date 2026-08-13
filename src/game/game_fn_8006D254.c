typedef signed int s32;

typedef struct Entry Entry;
typedef struct Owner Owner;
typedef void (*Callback)(Owner *owner);

struct Entry {
    unsigned char pad_0[0x1C];
    Callback callback;
};

struct Owner {
    void *pad_0;
    Entry *entries[3];
};

void fn_8006D254(Owner *owner)
{
    s32 i;

    for (i = 1; i < 3; i++) {
        Entry *entry = owner->entries[i];
        if (entry != 0 && entry->callback != 0) {
            entry->callback(owner);
        }
    }
}
