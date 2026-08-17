typedef unsigned char u8;

typedef struct Object {
    u8 pad[0x2A4];
    void* value;
} Object;

int fn_8012FB2C(Object* object)
{
    if (object != 0) {
        return object->value != 0;
    }
    return 0;
}
