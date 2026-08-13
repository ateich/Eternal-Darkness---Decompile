typedef short s16;

/*
 * NonMatching: behavior and the 0xE0-byte entry stride are recovered. MWCC
 * materializes lbl_80313120 through r0 before assigning the walking pointer,
 * while retail folds the low relocation directly into r4. Current objdiff:
 * 89.6875%, 64 target / 68 base bytes.
 */

typedef struct Entry {
    int field_00;
    int id;
    char pad_08[0xD8];
} Entry;

extern Entry lbl_80313120;

s16 fn_80072368(int id)
{
    s16 index = 0;
    char *entry;

    entry = (char *)&lbl_80313120;

    while (index < 0xAF) {
        if (id == *(int *)(entry + 4)) {
            return index;
        }
        entry += 0xE0;
        index++;
    }
    return -1;
}
