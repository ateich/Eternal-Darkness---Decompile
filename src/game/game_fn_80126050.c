typedef unsigned char u8;

typedef struct Owner {
    u8 pad[0x2A0];
    void* buffer;
} Owner;

extern unsigned char lbl_805A6500[];

int fn_80126050(Owner* owner)
{
    int result = 1;

    if (owner->buffer == lbl_805A6500)
        result = 0;
    return result;
}
