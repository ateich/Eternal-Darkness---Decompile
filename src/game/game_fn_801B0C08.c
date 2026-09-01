typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x144];
    unsigned int object;
    int handle;
    u8 pad14C[0x2E];
    u8 mode;
    u8 pad17B[9];
} Entry;

extern Entry lbl_8060B5E0[4];

int fn_801B0C08(unsigned int object)
{
    int result = -1;
    Entry* entry = lbl_8060B5E0;
    int i;

    for (i = 0; i < 4; i++, entry++) {
        if (entry->mode != 0 && entry->object == object) {
            result = entry->handle;
            break;
        }
    }
    return result;
}
