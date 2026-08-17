typedef unsigned char u8;

typedef struct Buffer {
    int state;
    int value;
} Buffer;

typedef struct Owner {
    u8 pad[0x2A0];
    Buffer* buffer;
} Owner;

int fn_801261E8(Owner* owner)
{
    return owner->buffer->value;
}
