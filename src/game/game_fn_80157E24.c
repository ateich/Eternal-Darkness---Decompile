typedef struct Entry {
    unsigned char pad[4];
    void* value;
    unsigned int flags;
} Entry;

void* fn_80157E24(Entry* entries, int index)
{
    return entries[index].value;
}
