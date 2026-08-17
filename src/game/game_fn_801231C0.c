typedef unsigned short u16;

typedef struct Object {
    unsigned char pad[0x8E];
    u16 value;
} Object;

u16 fn_801231C0(const Object* object)
{
    if (object->value == 0xA3A3) {
        return 4;
    }
    return object->value;
}
