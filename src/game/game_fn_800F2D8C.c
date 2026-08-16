typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int fn_800EFD6C(int *, TRKBuffer **);
extern int fn_800EFA84(TRKBuffer *, u32);
extern int fn_800F3054(TRKBuffer *, int *, int, int, int);
extern TRKBuffer *TRKGetBuffer(int);
extern int fn_800EFC6C(TRKBuffer *, int);
extern int fn_800EF86C(TRKBuffer *, u8 *);
extern void fn_800EFCDC(int);

static int append(TRKBuffer *buffer, u8 value)
{
    if (buffer->position >= 0x880)
        return 0x301;
    buffer->data[buffer->position++] = value;
    buffer->length++;
    return 0;
}

int fn_800F2D8C(u32 arg0, u8 *arg1)
{
    int reply_buffer;
    int first_buffer;
    TRKBuffer *buffer;
    int result;
    TRKBuffer *reply;

    result = fn_800EFD6C(&first_buffer, &buffer);
    if (result == 0)
        result = append(buffer, 0xD3);
    if (result == 0)
        result = fn_800EFA84(buffer, arg0);
    if (result == 0) {
        *arg1 = 0;
        result = fn_800F3054(buffer, &reply_buffer, 3, 3, 0);
        if (result == 0) {
            reply = TRKGetBuffer(reply_buffer);
            fn_800EFC6C(reply, 2);
        }
        if (result == 0)
            result = fn_800EF86C(reply, arg1);
        fn_800EFCDC(reply_buffer);
    }
    fn_800EFCDC(first_buffer);
    return result;
}
