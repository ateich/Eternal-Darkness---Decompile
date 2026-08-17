typedef struct Entry {
    int packed;
    int value;
    int key;
} Entry;

extern void fn_801292E0(void*, int*, Entry**);

int fn_8012939C(void* owner, int value, int keyed, int key, int* result,
                int start)
{
    int index = start + 1;
    int count;
    Entry* entries;
    int found = -1;

    fn_801292E0(owner, &count, &entries);
    if (count > 0 && index < count) {
        Entry* entry = &entries[index];
        int remaining = count - index;

        while (remaining-- > 0) {
            int key_matches = !keyed || (keyed && key == entry->key);
            if (entry->value == value && key_matches) {
                found = index;
                *result = entries[index].packed >> 17;
                break;
            }
            entry++;
            index++;
        }
    }
    return found;
}
