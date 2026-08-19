typedef struct Object {
    char pad0[0x14];
    int value;
    int result;
} Object;

extern void fn_8015F2B0(Object*, int*, int);
extern void fn_8015F12C(Object*, int, int, int, int);

void fn_8015F1F8(Object* object, int index, int value)
{
    if (value == object->value) {
        fn_8015F2B0(object, &object->result, index);
    } else {
        fn_8015F12C(object, index, value, 0, 0);
    }
}
