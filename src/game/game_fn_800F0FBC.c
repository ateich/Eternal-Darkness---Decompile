typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

extern int fn_800EFC6C(TRKBuffer *, u32);
extern void fn_800EFC9C(TRKBuffer *, u8);
extern int fn_800EF86C(TRKBuffer *, u8 *);
extern int fn_800EF7B4(TRKBuffer *, u16 *);
extern int fn_800EF2A0(TRKBuffer *);
extern int fn_800F4BCC(u32, u32, TRKBuffer *, u32 *, int);
extern int fn_800F4A90(u32, u32, TRKBuffer *, u32 *, int);
extern int fn_800F4920(u32, u32, TRKBuffer *, u32 *, int);
extern int fn_800F44E8(u32, u32, TRKBuffer *, u32 *, int);

static inline void append(TRKBuffer *buffer, u8 value)
{
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = value;
        buffer->length++;
    }
}

void fn_800F0FBC(TRKBuffer *buffer)
{
    u32 size;
    u16 start;
    u16 end;
    u8 message_command;
    u8 options;
    int result;
    int retry;
    u8 status;

    if (buffer->length <= 6) {
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, 2);
        retry = 3;
        do {
            result = fn_800EF2A0(buffer);
            retry--;
            if (result == 0) break;
        } while (retry > 0);
        return;
    }

    fn_800EFC6C(buffer, 0);
    result = fn_800EF86C(buffer, &message_command);
    if (result == 0) result = fn_800EF86C(buffer, &options);
    if (result == 0) result = fn_800EF7B4(buffer, &start);
    if (result == 0) result = fn_800EF7B4(buffer, &end);

    if (start > end) {
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, 0x14);
        retry = 3;
        do {
            result = fn_800EF2A0(buffer);
            retry--;
            if (result == 0) break;
        } while (retry > 0);
        return;
    }

    switch (options) {
    case 0:
        result = fn_800F4BCC(start, end, buffer, &size, 0);
        break;
    case 1:
        result = fn_800F4A90(start, end, buffer, &size, 0);
        break;
    case 2:
        result = fn_800F4920(start, end, buffer, &size, 0);
        break;
    case 3:
        result = fn_800F44E8(start, end, buffer, &size, 0);
        break;
    default:
        result = 0x703;
        break;
    }

    if (result == 0) {
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, 0);
    }

    if (result != 0) {
        switch (result) {
        case 0x703: status = 0x12; break;
        case 0x701: status = 0x14; break;
        case 0x302: status = 2; break;
        case 0x702: status = 0x15; break;
        case 0x704: status = 0x21; break;
        case 0x705: status = 0x22; break;
        case 0x706: status = 0x20; break;
        default: status = 3; break;
        }
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, status);
        retry = 3;
        do {
            result = fn_800EF2A0(buffer);
            retry--;
            if (result == 0) break;
        } while (retry > 0);
    } else {
        retry = 3;
        do {
            result = fn_800EF2A0(buffer);
            retry--;
            if (result == 0) break;
        } while (retry > 0);
    }
}
