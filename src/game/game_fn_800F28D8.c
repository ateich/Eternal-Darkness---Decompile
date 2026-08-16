typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

typedef struct TRKEvent {
    u8 type;
    u8 pad[3];
    u32 id;
    int buffer;
} TRKEvent;

extern int lbl_80329FE0;
extern int fn_800EFC9C(TRKBuffer *, int);
extern int fn_800EF2A0(TRKBuffer *);
extern void fn_800EEF1C(TRKEvent *, u8);
extern int fn_800EEF34(const TRKEvent *);

int fn_800F28D8(TRKBuffer *arg)
{
    TRKEvent event;
    TRKBuffer *buffer = arg;
    int retry;
    int result;

    lbl_80329FE0 = 0;
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
    if (result == 0) {
        fn_800EEF1C(&event, 1);
        fn_800EEF34(&event);
    }
    return result;
}
