typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memcpy(void*, const void*, u32);

typedef struct Entry {
    u8 pad_00[0x0A];
    u8 position[6];
    u8 pad_10[0x28];
} Entry;

typedef struct Object {
    u8 pad_00;
    u8 count;
    u8 pad_02[2];
    signed char state;
    u8 pad_05[5];
    u16 field_0A;
    u8 pad_0C[0x38];
    u32 field_44;
    u8 pad_48[4];
    Entry* entries;
    u8 pad_50[0x48];
    u8 position[6];
    u8 pad_9E[6];
    u16 flags;
} Object;

void fn_801851A0(Object* self, const void* position)
{
    int count;
    u8* entry;
    int index;
    u8* destination;
    Object* object;
    Object* saved_self;

    saved_self = self;
    destination = saved_self->position;
    /* Preserve destination - 0x98 through u8*: it re-derives self and reproduces retail's prologue scheduling. */
    object = (Object*)(destination - 0x98);
    object->flags &= ~0x10;
    object->flags |= 1;
    memcpy(destination, position, 6);
    saved_self->field_0A = 0;
    saved_self->field_44 = 0;
    saved_self->state = -2;

    entry = (u8*)saved_self->entries;
    count = saved_self->count;
    for (index = 0; index < count; index++) {
        memcpy(entry + 0x0A, position, 6);
        entry += 0x38;
    }
}
