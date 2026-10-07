typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct TRKBuffer {
    u32 unk0;
    u32 unk4;
    u32 length;
    u32 position;
    u8 data[1];
} TRKBuffer;

extern void fn_80003130(void *, const void *, u32);
extern int gTRKBigEndian[];

int fn_800EF604(TRKBuffer *buffer, u64 *out)
{
    u8 *destination;
    u8 *byte_data;
    u8 swap_buffer[sizeof(out)];
    int read_err;
    u32 amount;
    u32 remaining;

    if (gTRKBigEndian[0] != 0) {
        destination = (u8 *)out;
    } else {
        destination = swap_buffer;
    }
    amount = sizeof(*out);
    read_err = 0;
    remaining = buffer->length - buffer->position;
    if (amount > remaining) {
        read_err = 0x302;
        amount = remaining;
    }
    fn_80003130(destination, buffer->data + buffer->position, amount);
    buffer->position += amount;
    if (gTRKBigEndian[0] == 0 && read_err == 0) {
        byte_data = (u8 *)out;
        byte_data[0] = destination[7];
        byte_data[1] = destination[6];
        byte_data[2] = destination[5];
        byte_data[3] = destination[4];
        byte_data[4] = destination[3];
        byte_data[5] = destination[2];
        byte_data[6] = destination[1];
        byte_data[7] = destination[0];
    }
    return read_err;
}
