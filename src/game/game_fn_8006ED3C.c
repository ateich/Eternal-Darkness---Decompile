typedef struct Entry {
    int id;
} Entry;

typedef struct Owner {
    unsigned char pad_00[4];
    Entry *entries[3];
} Owner;

Entry *fn_8006ED3C(Owner *owner, int id, int *index)
{
    Owner *current;
    Entry *result;
    int i;

    *index = -1;
    current = owner;
    result = 0;
    i = 0;
    do {
        if (current->entries[0] != 0 && current->entries[0]->id == id) {
            *index = i;
            result = owner->entries[i];
            break;
        }
        current = (Owner *)((unsigned char *)current + 4);
        i++;
    } while (i < 3);
    return result;
}
