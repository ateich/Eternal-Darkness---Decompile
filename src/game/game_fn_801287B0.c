typedef unsigned char u8;

typedef struct Owner {
    u8 pad0[0x134];
    void* value;
} Owner;

void* fn_801287B0(Owner* owner, void* value)
{
    void* previous = owner->value;
    owner->value = value;
    return previous;
}
