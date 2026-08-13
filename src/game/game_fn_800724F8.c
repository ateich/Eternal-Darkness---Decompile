typedef struct Entry {
    int field_00;
    int id;
    char pad_08[0xD8];
} Entry;

extern Entry lbl_80313120[];
extern int fn_80072368(int);
extern void *memcpy(void *, const void *, unsigned int);

int fn_800724F8(Entry *entry)
{
    int index;

    if (entry != 0 && fn_80072368(entry->id) == -1) {
        index = fn_80072368(-1);
        memcpy(&lbl_80313120[index], entry, sizeof(Entry));
    }
    return 0;
}
