typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex, in_use, length, position;
    u8 data[0x880];
} TRKBuffer;

typedef struct CPUType {
    u8 cpuMajor;
    u8 cpuMinor;
    u8 bigEndian;
    u8 defaultTypeSize;
    u8 fpTypeSize;
    u8 extended1TypeSize;
    u8 extended2TypeSize;
} CPUType;

extern void fn_800EFC9C(TRKBuffer *, u8);
extern int fn_800EF2A0(TRKBuffer *);
extern int fn_800F43C0(CPUType *);

static inline void append(TRKBuffer *buffer, u8 value)
{
    if (buffer->position < 0x880) {
        buffer->data[buffer->position++] = value;
        buffer->length++;
    }
}

static inline int appendChecked(TRKBuffer *buffer, u8 value)
{
    if (buffer->position >= 0x880)
        return 0x301;
    buffer->data[buffer->position++] = value;
    buffer->length++;
    return 0;
}

void fn_800F1F80(TRKBuffer *buffer)
{
    CPUType cpuType;
    int result;
    int retry;

    if (buffer->length != 1) {
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

    fn_800EFC9C(buffer, 1);
    append(buffer, 0x80);
    append(buffer, 0);

    result = fn_800F43C0(&cpuType);
    if (result == 0) result = appendChecked(buffer, cpuType.cpuMajor);
    if (result == 0) result = appendChecked(buffer, cpuType.cpuMinor);
    if (result == 0) result = appendChecked(buffer, cpuType.bigEndian);
    if (result == 0) result = appendChecked(buffer, cpuType.defaultTypeSize);
    if (result == 0) result = appendChecked(buffer, cpuType.fpTypeSize);
    if (result == 0) result = appendChecked(buffer, cpuType.extended1TypeSize);
    if (result == 0) result = appendChecked(buffer, cpuType.extended2TypeSize);

    if (result != 0) {
        fn_800EFC9C(buffer, 1);
        append(buffer, 0x80);
        append(buffer, 3);
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
