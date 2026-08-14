typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Object800A3274 Object800A3274;

typedef struct VTable800A3274 {
    u8 pad00[0x48];
    void (*callback)(Object800A3274*, u32, u16);
} VTable800A3274;

struct Object800A3274 {
    VTable800A3274* vtable;
    u8 pad004[0x82];
    u16 value;
    u8 pad088[0x1FC];
    u16 state;
};

extern u32 lbl_8064C940;

void fn_800A3274(Object800A3274* object, u32 arg, u32 value)
{
    u16 old_value = object->value;
    object->value = value;
    lbl_8064C940 = value;
    object->state = 2;
    object->vtable->callback(object, arg, old_value);
}
