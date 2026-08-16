typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int fn_800EFD6C(int *, TRKBuffer **);
extern int fn_800F4080(TRKBuffer *);
extern int fn_800F3FD4(TRKBuffer *);
extern int fn_800F3054(TRKBuffer *, int *, int, int, int);
extern void fn_800EFCDC(int);

static int append(TRKBuffer *buffer, u8 value)
{
    if (buffer->position >= 0x880)
        return 0x301;
    buffer->data[buffer->position++] = value;
    buffer->length++;
    return 0;
}

int fn_800F34D4(u8 command)
{
    int reply_buffer;
    int first_buffer;
    TRKBuffer *buffer;
    int append_result;
    int result;

    result = fn_800EFD6C(&first_buffer, &buffer);
    if (result == 0) {
        append_result = append(buffer, command);
        if (append_result == 0) {
            if (command == 0x90)
                fn_800F4080(buffer);
            else
                fn_800F3FD4(buffer);
        }
        result = fn_800F3054(buffer, &reply_buffer, 2, 3, 1);
        if (result == 0)
            fn_800EFCDC(reply_buffer);
        fn_800EFCDC(first_buffer);
    }
    return result;
}
