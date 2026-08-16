typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int fn_800F3C60(void);
extern int fn_800EFC9C(TRKBuffer *, int);
extern int fn_800EF2A0(TRKBuffer *);

void fn_800F0540(TRKBuffer *buffer)
{
    int response;
    int retry;

    switch (fn_800F3C60()) {
    case 0: response = 0; break;
    case 0x704: response = 0x21; break;
    case 0x705: response = 0x22; break;
    case 0x706: response = 0x20; break;
    default: response = 1; break;
    }
    fn_800EFC9C(buffer, 1);
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = 0x80;
        buffer->length++;
    }
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = response;
        buffer->length++;
    }
    retry = 3;
    do {
        int result = fn_800EF2A0(buffer);
        retry--;
        if (result == 0) break;
    } while (retry > 0);
}
