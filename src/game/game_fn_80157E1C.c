typedef struct Object {
    unsigned char pad[0x184];
    int count;
} Object;

int fn_80157E1C(Object* object)
{
    return object->count;
}
