typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A2430 {
    u8 pad000[0x284];
    u16 value;
} Object800A2430;

extern int fn_800A30AC(Object800A2430*);

void fn_800A2430(Object800A2430* object, u16 value, void* unused, int* result)
{
    if (fn_800A30AC(object)) {
        if (result != 0) {
            *result = 0;
        }
    } else {
        object->value = value;
        if (result != 0) {
            *result = 1;
        }
    }
}
