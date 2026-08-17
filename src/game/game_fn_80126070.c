typedef unsigned char u8;

typedef struct Owner {
    u8 pad[0x2A0];
    void* buffer;
} Owner;

int fn_80126070(Owner* owner)
{
    return owner->buffer != 0;
}
