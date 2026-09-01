typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x15C];
    int owner;
    u8 pad160[0x1A];
    u8 mode;
    u8 pad17B[9];
} Entry;

extern Entry lbl_8060B5E0[4];

Entry* fn_801B0A6C(int owner)
{
    Entry* entry;
    int i;

    if (owner != -1) {
        entry = lbl_8060B5E0;
        for (i = 0; i < 4; i++, entry++) {
            if (entry->mode != 0 && entry->mode != 1 &&
                entry->owner == owner) {
                return entry;
            }
        }
    }

    return 0;
}
