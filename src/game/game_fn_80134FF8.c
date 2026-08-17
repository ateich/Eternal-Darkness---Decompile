typedef unsigned char u8;

typedef struct Object Object;

typedef struct Slot {
    Object* owner;
    unsigned int capacity;
    void* data;
    int field_C;
    int field_10;
    char pad_14[2];
    u8 state;
    u8 pad_17;
} Slot;

struct Object {
    char pad_0[0x124];
    Slot* slot;
};

extern int fn_801261F4(void*);
extern Slot* fn_8013507C(void*, Object*);

int fn_80134FF8(void* manager, Object* object)
{
    fn_801261F4(manager);
    if (object->slot != 0 && object->slot->owner != object)
        object->slot = 0;
    if (object->slot == 0)
        object->slot = fn_8013507C(manager, object);
    object->slot->state = 4;
    return 0;
}
