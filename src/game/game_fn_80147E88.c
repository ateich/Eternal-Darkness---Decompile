extern void* memset(void*, int, unsigned int);

typedef struct Entry {
    unsigned char bytes[0xC0];
} Entry;

void fn_80147E88(Entry* entry)
{
    memset(entry, 0, sizeof(*entry));
    entry->bytes[0xBE] = 100;
}
