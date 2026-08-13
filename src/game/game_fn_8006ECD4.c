typedef struct Entry {
    int id;
} Entry;

typedef struct Owner {
    unsigned char pad_00[4];
    Entry *entries[3];
} Owner;

int fn_8006ECD4(Owner *owner, int id)
{
    int result;
    Entry *entry;

    result = -1;
    entry = owner->entries[0];
    if (entry != 0 && entry->id == id) {
        result = 0;
    } else if ((entry = owner->entries[1]) != 0 && entry->id == id) {
        result = 1;
    } else if ((entry = owner->entries[2]) != 0 && entry->id == id) {
        result = 2;
    }
    return result;
}
