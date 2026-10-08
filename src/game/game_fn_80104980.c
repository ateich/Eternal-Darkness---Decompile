typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry80104980 Entry80104980;

typedef struct Work80104980 {
    int index;
    int *current;
    u16 *start;
    int *end;
    u16 value0;
    u16 value1;
    u8 byte14;
} Work80104980;

extern void fn_8010483C(Entry80104980 *, int *, int, Work80104980 *, u16 *);

void fn_80104980(Entry80104980 *entries, int *output, int width,
                  Work80104980 *work, int columns)
{
    u16 *current;

    columns--;
    work->value0 = *work->start;
    work->byte14 = *(u8 *)work->start;

    while (columns > 0) {
        work->value1 = work->value0;
        current = work->start + 1;
        work->start = current;
        work->value0 = *current;
        fn_8010483C(entries, output, width, work, current);
        output++;
        columns--;
    }

    work->value1 = work->value0;
    current = work->start;
    work->start = current + 3;
    fn_8010483C(entries, output, width, work, current);
    work->current++;
    work->end++;
}
