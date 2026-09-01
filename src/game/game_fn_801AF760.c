typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x148];
    int id;
    u8 pad14c[0x2e];
    u8 state;
    u8 pad17b[9];
} Entry;

extern Entry lbl_8060B5E0[];

Entry* fn_801AF760(int id)
{
    Entry* entry;
    int i;

    if (id != -1) {
        for (i = 0, entry = lbl_8060B5E0; i < 4; i++, entry++) {
            if (entry->state != 0 && entry->state != 1 && entry->id == id) {
                return entry;
            }
        }
    }
    return 0;
}
