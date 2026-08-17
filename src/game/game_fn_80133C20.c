typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Object {
    char pad_0[0x254];
    int flags;
} Object;

typedef struct Manager {
    char pad_0[5];
    u8 count;
    char pad_6[10];
    char* entries;
} Manager;

typedef struct Selection {
    char pad_0[0x70];
    int* indices;
    char pad_74[8];
    u8 count;
} Selection;

extern void fn_8012C478(Object*, int, int);

void fn_80133C20(Manager* manager, Selection* selection)
{
    int i = 0;
    int offset = 0;

    while (i < manager->count) {
        Object* object = *(Object**)(manager->entries + offset);
        if (object != 0) {
            object->flags |= 0x08000000;
            fn_8012C478(object, 0xF, 0);
        }
        offset += 0x28;
        i++;
    }

    offset = 0;
    i = 0;
    while (offset < selection->count) {
        int entry_offset = *(int*)((char*)selection->indices + i) * 0x28;
        Object* object = *(Object**)(manager->entries + entry_offset);
        if (object != 0) {
            object->flags &= ~0x08000000;
            fn_8012C478(object, 0xF, 1);
        }
        i += 4;
        offset++;
    }
}
