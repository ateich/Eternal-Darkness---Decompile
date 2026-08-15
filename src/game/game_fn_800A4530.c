typedef unsigned char u8;

typedef struct Object800A4530 {
    u8 pad0[0x24c];
    int child;
} Object800A4530;

extern unsigned long long fn_8020123C();

int fn_800A4530(Object800A4530* object, int arg1, int arg2, int clear)
{
    Object800A4530* cursor;
    unsigned int i;
    int count;
    int zero;

    cursor = object;
    count = 0;
    zero = 0;
    for (i = 0; i < 4; i++, cursor = (Object800A4530*)((u8*)cursor + 4)) {
        if (cursor->child != 0) {
            fn_8020123C(arg1, arg2, cursor->child, 0);
            if (clear != 0) {
                cursor->child = zero;
            }
            count++;
        }
    }
    return count;
}
