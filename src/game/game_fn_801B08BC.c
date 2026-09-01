typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    int object;
    int handle;
    u8 pad14C[0x10];
    int owner;
    u8 pad160[0x1A];
    u8 mode;
    u8 pad17B[2];
    u8 direct;
    u8 pad17E[6];
} Entry;

extern Entry lbl_8060B5E0[4];
extern void fn_801B01F8(Entry*, int, int);

int fn_801B08BC(int handle, int owner)
{
    int count = 0;
    int i;
    Entry* entry = lbl_8060B5E0;

    for (i = 0; i < 4; i++, entry++) {
        if ((handle != -1 && entry->handle == handle) ||
            (owner != -2 && entry->owner == owner) || owner == -1) {
            if ((entry->mode == 4 || entry->mode == 5 || entry->mode == 6) &&
                entry->direct == 0) {
                fn_801B01F8(entry, 0, 9);
                count++;
            }
        }
    }

    return count;
}
