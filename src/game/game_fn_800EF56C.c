typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 unk0;
    u32 unk4;
    u32 length;
    u32 position;
    u8 data[1];
} TRKBuffer;

extern void fn_80003130(void *, const void *, u32);

int fn_800EF56C(TRKBuffer *buffer, u8 *out, int count)
{
    int i = 0;
    int err = 0;

    while (err == 0 && i < count) {
        u32 amount = 1;
        int read_err = 0;
        u32 remaining = buffer->length - buffer->position;

        if (amount > remaining) {
            read_err = 0x302;
            amount = remaining;
        }
        fn_80003130(out + i, buffer->data + buffer->position, amount);
        buffer->position += amount;
        err = read_err;
        i++;
    }
    return err;
}
