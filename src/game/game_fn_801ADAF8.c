typedef struct Entry {
    unsigned char active;
    unsigned char padding[3];
    unsigned int id;
    unsigned char remainder[124];
} Entry;

extern Entry lbl_8060B430[];

int fn_801ADAF8(unsigned int id)
{
    int index;
    Entry* entry;

    entry = lbl_8060B430;
    for (index = 0; index < 3; index++, entry++) {
        if (entry->active != 0 && id == entry->id) {
            return index;
        }
    }

    return -1;
}
