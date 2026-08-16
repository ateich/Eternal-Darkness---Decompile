extern void *memset(void *, int, unsigned int);
typedef struct Entry {
    unsigned char data[32];
} Entry;
extern Entry lbl_80325C40[];

/* NonMatching: behavior and loop structure match; MWCC retains an extra
 * address temporary before assigning the table cursor (92.72727%). */

void fn_800E475C(void)
{
    Entry *entry;
    int i;

    entry = lbl_80325C40;
    for (i = 0; i < 5; i++, entry++)
        memset(entry, 0, 32);
}
