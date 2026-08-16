typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int fn_800EFC6C(TRKBuffer *, int);
extern int fn_800EF86C(TRKBuffer *, u8 *);
extern int fn_800EFC9C(TRKBuffer *, int);
extern int fn_800EF2A0(TRKBuffer *);
extern void fn_800F593C(u8);

static void append(TRKBuffer *buffer, u8 value)
{
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = value;
        buffer->length++;
    }
}

void fn_800F039C(TRKBuffer *buffer)
{
    u8 a = 0, b = 0, c = 0;
    int result, retry;

    fn_800EFC6C(buffer, 0);
    result = fn_800EF86C(buffer, &a);
    if (result == 0) result = fn_800EF86C(buffer, &b);
    if (result == 0) result = fn_800EF86C(buffer, &c);
    if (result != 0) {
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, 1);
        retry = 3;
        do {
            result = fn_800EF2A0(buffer);
            retry--;
            if (result == 0) break;
        } while (retry > 0);
    } else if (b == 1) {
        fn_800F593C(c);
    }
    fn_800EFC9C(buffer, 1);
    append(buffer, 0x80);
    append(buffer, 0);
    retry = 3;
    do {
        result = fn_800EF2A0(buffer);
        retry--;
        if (result == 0) break;
    } while (retry > 0);
}
