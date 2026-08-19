typedef struct Entry {
    int sentinel;
    char pad04[0x194];
} Entry;

extern Entry lbl_805B4E10[];
extern void* memset(void*, int, unsigned int);

int fn_80158668(Entry* entry)
{
    if (entry >= lbl_805B4E10 && entry < &lbl_805B4E10[20]) {
        memset(entry, 0, sizeof(Entry));
        entry->sentinel = -1;
        return 1;
    }
    return 0;
}
