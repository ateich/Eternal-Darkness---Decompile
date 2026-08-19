typedef struct Object {
    unsigned char pad0[0x14];
    int current;
    int value;
} Object;

extern int fn_8015F9B0(Object*, int, int);
extern void fn_8015F2B0(Object*, int*, int);

int fn_8015EAD0(Object* object)
{
    int result = fn_8015F9B0(object, 42, -1);

    if (result == object->current) {
        fn_8015F2B0(object, &result, object->value);
        object->value = -1;
    }
    return result;
}
