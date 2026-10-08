typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry80104A54 {
    u8 pad00[4];
    u16 *data;
    u16 columns;
    u16 rows;
    u16 stride;
    u8 pad0E[0x1A];
    u16 width;
    u8 pad2A[0xE];
} Entry80104A54;

typedef struct Work80104A54 {
    int index;
    u16 *current;
    u16 *start;
    u16 *end;
    u16 value0;
    u16 value1;
    u8 byte14;
} Work80104A54;

extern void fn_80104980(Entry80104A54 *, void *, int, Work80104A54 *, int);

void fn_80104A54(Entry80104A54 *entries, int index, int *output)
{
    Work80104A54 work;
    Entry80104A54 *entry;
    u16 columns;
    u16 width;
    int row;

    entry = &entries[index];
    width = entry->width;
    columns = entry->columns;
    work.index = index;
    work.current = entry->data;
    work.start = entry->data;
    work.end = entry->data + entry->stride;

    fn_80104980(entries, output, width, &work, columns);
    output += width;
    work.current = entry->data;

    row = entry->rows - 2;
    while (row > 0) {
        fn_80104980(entries, output, width, &work, columns);
        output += width;
        row--;
    }

    work.end = work.start;
    fn_80104980(entries, output, width, &work, columns);
}
