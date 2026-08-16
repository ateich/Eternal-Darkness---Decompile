typedef unsigned char u8;
typedef unsigned int u32;
typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;
extern int fn_800EFC9C(TRKBuffer *, int);
extern int fn_800EF2A0(TRKBuffer *);

void fn_800F2B28(TRKBuffer *buffer, int first, int second)
{
    int retry;
    fn_800EFC9C(buffer, 1);
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = first;
        buffer->length++;
    }
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = second;
        buffer->length++;
    }
    retry = 3;
    do {
        int result = fn_800EF2A0(buffer);
        retry--;
        if (result == 0) break;
    } while (retry > 0);
}
