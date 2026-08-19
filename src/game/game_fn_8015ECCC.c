typedef struct Object {
    unsigned char pad0[0x28];
    void* value;
} Object;

extern int fn_8015F9B0(void*, int, int);

int fn_8015ECCC(Object* object, int value)
{
    return fn_8015F9B0(object->value, 7, value);
}
