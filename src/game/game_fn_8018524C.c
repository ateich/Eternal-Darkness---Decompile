typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memcpy(void*, const void*, u32);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern u8 fn_8018E26C(void*, void*);

typedef struct Entry {
    u8 active;
    u8 pad_01[9];
    u8 position[6];
    u8 pad_10[0x1B];
    u8 field_2B;
    u8 pad_2C[0x0C];
} Entry;

typedef struct Object {
    u8 pad_00;
    u8 count;
    u8 pad_02[2];
    u8 field_04;
    u8 pad_05[5];
    u16 counter;
    u16 limit;
    u8 pad_0E[0x14];
    u16 state;
    u8 pad_24[0x28];
    Entry* entries;
    u8 pad_50[0x44];
    u32 field_94;
    u8 position[12];
    u16 flags;
} Object;

u32 fn_8018524C(Object* self)
{
    int count;
    int old_counter;
    u8* position;
    Entry* entry;
    Object* saved_self;
    int index;
    Entry* entry1;
    Entry* destination0;
    Entry* source0;
    Entry* destination1;
    Entry* source1;

    position = (u8*)self + 0x98;
    saved_self = (Object*)(position - 0x98);
    old_counter = saved_self->counter;
    entry = saved_self->entries;
    count = saved_self->count;
    saved_self->counter = old_counter + 1;

    destination0 = entry + (count - 2);
    entry1 = entry + 1;
    destination1 = entry1 + (count - 2);
    source0 = destination0 - 2;
    source1 = destination1 - 2;

    if (saved_self->flags & 1) {
        index = (count >> 1) - 1;
        while (index > 0) {
            memcpy(destination0->position, source0->position, 6);
            memcpy(destination1->position, source1->position, 6);
            destination0 -= 2;
            source0 -= 2;
            destination1 -= 2;
            source1 -= 2;
            index--;
        }
        memcpy(entry[0].position, position, 6);
        memcpy(entry1->position, position + 6, 6);
        saved_self->flags &= ~1;
    }

    if (saved_self->flags & 0x10) {
        Entry* current = entry;
        for (index = 0; index < count; index++, current++) {
            if (current->active)
                fn_8018E26C(current, &current->field_2B);
        }
    }

    if (saved_self->flags & 8) {
        saved_self->flags |= 0x10;
        saved_self->flags &= ~8;
        for (index = 0; index < count; index++, entry++) {
            fn_8018E230(entry, &entry->field_2B, 1, entry->field_2B,
                        saved_self->field_04, 0);
        }
    }

    if (saved_self->field_94 == 0 &&
        ((saved_self->flags & 2) != 0 || old_counter > saved_self->limit)) {
        saved_self->state = 8;
    }
    return 0;
}
