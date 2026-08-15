typedef struct FreeEntry {
    unsigned char pad[12];
    unsigned char flags;
    unsigned char tail[3];
} FreeEntry;

extern FreeEntry *lbl_8064CA78;

FreeEntry *fn_800BD5F4(void)
{
    FreeEntry *entry = lbl_8064CA78;
    int i;

    for (i = 0; i < 500; i++, entry++) {
        if ((entry->flags & 1) == 0) {
            entry->flags |= 1;
            return entry;
        }
    }
    return 0;
}
