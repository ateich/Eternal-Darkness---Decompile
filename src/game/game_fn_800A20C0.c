typedef unsigned char u8;

typedef struct Object800A20C0 {
    u8 pad000[0x28C];
    void* state;
    u8 pad290[0x12];
    u8 pad_bits : 2;
    u8 active : 1;
    u8 remaining_bits : 5;
} Object800A20C0;

extern int fn_801AF85C(void*);
extern int fn_801AF8A4(void*);

int fn_800A20C0(Object800A20C0* object)
{
    int result = 0;
    object->active = fn_801AF85C(object->state);
    if (object->active) {
        result = 1;
        if (fn_801AF8A4(object->state)) {
            result = 2;
        }
    }
    return result;
}
