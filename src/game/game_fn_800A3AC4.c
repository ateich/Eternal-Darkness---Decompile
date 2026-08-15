typedef unsigned char u8;

typedef struct Object800A3AC4 Object800A3AC4;
typedef struct Vtable800A3AC4 {
    u8 pad0[0x3C];
    void (*callback)(Object800A3AC4*);
} Vtable800A3AC4;

struct Object800A3AC4 {
    Vtable800A3AC4* vtable;
    u8 pad4[0x193];
    u8 state;
};

void fn_800A3AC4(Object800A3AC4* object)
{
    object->state = 0;
    object->vtable->callback(object);
}
