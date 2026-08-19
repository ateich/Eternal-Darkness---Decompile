typedef struct Entry {
    char pad00[8];
    int active;
} Entry;

void fn_80158850(Entry* entry)
{
    entry->active = 0;
}
