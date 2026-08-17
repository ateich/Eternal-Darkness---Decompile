typedef struct Entry {
    int value;
    int object;
    int resource;
    int callback;
    int state;
    int index;
    unsigned short flags;
    unsigned short pad;
} Entry;

typedef struct PackedEntry {
    unsigned char flags;
    unsigned char index;
    short value;
    short object;
    short pad;
    int resource;
    short callback;
    unsigned short entry_flags;
} PackedEntry;

extern Entry lbl_80332428[];
extern void fn_8011E884(Entry*, PackedEntry*);
extern void* memcpy(void*, const void*, unsigned long);

unsigned long fn_8011E918(void* dst)
{
    PackedEntry packed;

    fn_8011E884(&lbl_80332428[2], &packed);
    memcpy(dst, &packed, sizeof(PackedEntry));
    fn_8011E884(&lbl_80332428[4], &packed);
    memcpy((char*)dst + sizeof(PackedEntry), &packed, sizeof(PackedEntry));
    return 2 * sizeof(PackedEntry);
}
