typedef unsigned char u8;
typedef struct Object800A383C { u8 pad0[0x29E]; signed char count; } Object800A383C;
extern void fn_800A1E94(Object800A383C*);
extern void fn_800A1FC0(Object800A383C*);

int fn_800A383C(Object800A383C* object)
{
    int result = 0;
    object->count--;
    if (object->count == 0) {
        fn_800A1E94(object);
        fn_800A1FC0(object);
        result = 1;
    }
    return result;
}
