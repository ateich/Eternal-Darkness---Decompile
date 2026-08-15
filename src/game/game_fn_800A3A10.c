typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct Object800A3A10 {
    u8 pad0[0x84];
    u16 flags;
    u8 pad86[0x112];
    int index;
} Object800A3A10;

extern int fn_801A74C0(void*);
extern int fn_801A7590(void*);

int fn_800A3A10(Object800A3A10* object, s16* values, void* runtime)
{
    int active;
    int result;

    result = 0;
    active = 0;

    if ((object->flags & 1) != 0) {
        if ((fn_801A74C0(runtime) & 0x10000) != 0) {
            active = 1;
        }
    }

    if (active != 0) {
        int state = fn_801A7590(runtime);
        int mask = 0x8000;
        if (object->index != -1 && values[object->index] > 0) {
            mask |= 1 << object->index;
        }
        if ((state & mask) != 0) {
            result = 1;
        }
    } else {
        fn_801A7590(runtime);
    }
    return result;
}
