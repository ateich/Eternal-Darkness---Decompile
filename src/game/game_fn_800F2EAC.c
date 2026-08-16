typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int fn_800EFD6C(int *, TRKBuffer **);
extern int fn_800EFAE8(TRKBuffer *, u16);
extern int fn_800EF994(TRKBuffer *, const void *, u32);
extern int fn_800F3054(TRKBuffer *, int *, int, int, int);
extern TRKBuffer *TRKGetBuffer(int);
extern int fn_800EFC6C(TRKBuffer *, int);
extern int fn_800EF86C(TRKBuffer *, u8 *);
extern int fn_800EF6EC(TRKBuffer *, u32 *);
extern void fn_800EFCDC(int);
extern u32 strlen(const char *);

static int append(TRKBuffer *buffer, u8 value)
{
    if (buffer->position >= 0x880)
        return 0x301;
    buffer->data[buffer->position++] = value;
    buffer->length++;
    return 0;
}

int fn_800F2EAC(const char *name, u8 kind, u32 *value, u8 *status)
{
    int reply_buffer;
    int first_buffer;
    TRKBuffer *buffer;
    TRKBuffer *reply;
    int result;

    *value = 0;
    result = fn_800EFD6C(&first_buffer, &buffer);
    if (result == 0)
        result = append(buffer, 0xD2);
    if (result == 0)
        result = append(buffer, kind);
    if (result == 0)
        result = fn_800EFAE8(buffer, (u16)(strlen(name) + 1));
    if (result == 0)
        result = fn_800EF994(buffer, name, strlen(name) + 1);
    if (result == 0) {
        *status = 0;
        result = fn_800F3054(buffer, &reply_buffer, 7, 3, 0);
        if (result == 0) {
            reply = TRKGetBuffer(reply_buffer);
            fn_800EFC6C(reply, 2);
        }
        if (result == 0)
            result = fn_800EF86C(reply, status);
        if (result == 0)
            result = fn_800EF6EC(reply, value);
        fn_800EFCDC(reply_buffer);
    }
    fn_800EFCDC(first_buffer);
    return result;
}
