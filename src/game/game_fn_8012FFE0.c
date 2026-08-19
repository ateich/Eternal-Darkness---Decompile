typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x44];
    int state;
    u8 pad48[4];
    unsigned int mask;
    u8 pad50[4];
    u8 flags;
    u8 index;
} RuntimeState;

typedef struct Object {
    u8 pad[0x290];
    RuntimeState* runtime;
} Object;

extern void fn_80125ECC(void *);

int fn_8012FFE0(Object* object, int flags, u8 index)
{
    int result = 1;
    RuntimeState* runtime;

    fn_80125ECC(object);
    runtime = object->runtime;
    if ((runtime->flags & 0x70) != 0 ||
        (runtime->mask & (1U << index)) != 0) {
        result = 0;
    }
    if (result && runtime->state > 0 && index <= runtime->index) {
        if (index < runtime->index) {
            result = 0;
        } else if ((flags & 4) == 0) {
            result = 0;
        }
    }
    return result;
}
