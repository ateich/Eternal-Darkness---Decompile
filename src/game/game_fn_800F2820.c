typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int fn_800EFC9C(TRKBuffer *, int);
extern int fn_800EF2A0(TRKBuffer *);
extern void fn_80005088(void);

int fn_800F2820(TRKBuffer *buffer)
{
    int retry;
    int result;

    fn_800EFC9C(buffer, 1);
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = 0x80;
        buffer->length++;
    }
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = 0;
        buffer->length++;
    }
    retry = 3;
    do {
        result = fn_800EF2A0(buffer);
        retry--;
        if (result == 0)
            break;
    } while (retry > 0);
    fn_80005088();
    return 0;
}
