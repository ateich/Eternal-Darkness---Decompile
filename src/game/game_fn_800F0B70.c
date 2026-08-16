typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int TRKTargetStopped(void);
extern void TRKTargetContinue(void);
extern int fn_800EFC9C(TRKBuffer *, int);
extern int fn_800EF2A0(TRKBuffer *);

static void append(TRKBuffer *buffer, u8 value)
{
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = value;
        buffer->length++;
    }
}

void fn_800F0B70(TRKBuffer *buffer)
{
    int retry;
    int result;

    if (!TRKTargetStopped()) {
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, 0x16);
        retry = 3;
        do {
            result = fn_800EF2A0(buffer);
            retry--;
            if (result == 0) break;
        } while (retry > 0);
    } else {
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, 0);
        retry = 3;
        do {
            result = fn_800EF2A0(buffer);
            retry--;
            if (result == 0) break;
        } while (retry > 0);
        if (result == 0)
            TRKTargetContinue();
    }
}
