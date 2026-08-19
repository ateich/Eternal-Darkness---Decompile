typedef struct Entry {
    int sentinel;
    char pad04[0x194];
} Entry;

extern Entry lbl_805B4E10[];
extern void* memset(void*, int, unsigned int);

void fn_8015761C(void)
{
    Entry* end;
    Entry* entry;

    entry = lbl_805B4E10;
    end = entry + 20;
    while (entry < end) {
        memset(entry, 0, sizeof(Entry));
        entry->sentinel = -1;
        entry++;
    }
}
