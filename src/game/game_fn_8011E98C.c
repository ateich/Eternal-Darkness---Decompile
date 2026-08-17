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
extern void fn_8011E8D8(PackedEntry*, Entry*);
extern void* memcpy(void*, const void*, unsigned long);

unsigned long fn_8011E98C(void* src)
{
    PackedEntry packed;

    memcpy(&packed, src, sizeof(PackedEntry));
    fn_8011E8D8(&packed, &lbl_80332428[2]);
    memcpy(&packed, (char*)src + sizeof(PackedEntry), sizeof(PackedEntry));
    fn_8011E8D8(&packed, &lbl_80332428[4]);
    return 2 * sizeof(PackedEntry);
}
