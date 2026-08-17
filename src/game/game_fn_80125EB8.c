typedef unsigned char u8;

typedef struct Object {
    u8 pad[0x767];
    unsigned char pad_flags : 7;
    unsigned char enabled : 1;
} Object;

typedef struct Owner {
    u8 pad[0x2A4];
    Object* object;
} Owner;

void fn_80125EB8(Owner* owner, unsigned int enabled)
{
    owner->object->enabled = enabled;
}
