typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

#define NULL 0
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef struct Entry {
    u32 size;
    u32 pad4;
    u32 index;
    int object_index;
} Entry;

typedef struct EntryList {
    u32 total_size;
    u32 pad4;
    Entry* entries;
    u32 padC;
    int count;
} EntryList;

typedef struct Runtime {
    unsigned char pad[0x60];
    unsigned char* objects;
} Runtime;

typedef struct Object {
    unsigned char pad0[0x3C];
    Runtime* runtime;
    unsigned char pad40[0x140];
    u16 object_state[16];
    unsigned char pad1A0[0xB4];
    u32 state_flags;
    unsigned char pad258[0x80];
    s8 fade_step;
    u8 fade_level;
} Object;

typedef struct Material {
    u8 pad00[0x1F];
    u8 alpha;
} Material;

extern void fn_801ECF50(int mode);
extern void fn_801ED118(void);
extern EntryList* fn_801222A0(Runtime* runtime, int kind, int mode, int unused);
extern void fn_80122428(Runtime* runtime, EntryList* list, int kind, int mode, int unused);
extern void fn_801ED5F4(int, int, s16, float*, float (*)[4], float);
extern void fn_801EDA7C(void* destination, void* manager, int type, int value);
extern void fn_801ECEC8(int, int, int);
extern void fn_8022A5D8(int, int, int, int);
extern void fn_8022A6DC(int);
extern void fn_8022A71C(int);
extern void fn_8022B448(u32 offset, u32 size);
extern Material lbl_8024EDE8[];
extern const float lbl_806500A0;

void fn_801227A0(Object* object, int kind, int inverted)
{
    Runtime* runtime;
    int mode = 7;
    EntryList* list;
    int i;
    Entry* entry;
    u32 offset;

    runtime = object->runtime;
    if (object->state_flags & 0x00400000) {
        mode = 1;
    }
    fn_801ECF50(mode);
    fn_801ED118();
    list = fn_801222A0(runtime, kind, mode, 0);
    if (list->total_size == 0) {
        fn_80122428(runtime, list, kind, mode, 0);
    }

    if (!(object->state_flags & 0x00040000)) {
        return;
    }

    object->fade_level = MIN(MAX(object->fade_level + object->fade_step, 50), 150);

    lbl_8024EDE8[1].alpha = object->fade_level;
    fn_801ED5F4(0, 0, 0, NULL, NULL, lbl_806500A0);
    if (inverted) {
        lbl_8024EDE8[1].alpha = 305 - object->fade_level;
    }
    if (object->fade_level == 50 || object->fade_level == 150) {
        object->fade_step = -object->fade_step;
    }
    fn_801EDA7C(&lbl_8024EDE8[1], 0, 0x2BF, 0);

    if (inverted) {
        fn_8022A71C(1);
        fn_8022A6DC(0);
        fn_801ECEC8(1, 3, 1);
        fn_8022A5D8(2, 4, 5, 3);
        entry = list->entries;
        offset = list->total_size;
        for (i = 0; i < list->count; entry++, i++) {
            if (entry->size != 0 &&
                (object->object_state[entry->object_index * 4] & 5) == 5) {
                fn_8022B448(offset, entry->size);
            }
            offset += entry->size;
        }
        entry = list->entries;
        for (i = 0; i < list->count; entry++, i++) {
            object->object_state[entry->object_index * 4] &= ~2;
        }
        object->state_flags &= ~0x00040000u;
        fn_8022A5D8(1, 4, 5, 15);
        fn_8022A6DC(1);
        fn_8022A71C(0);
    } else {
        fn_8022A6DC(1);
        fn_8022A71C(0);
        fn_801ECEC8(1, 3, 1);
        fn_8022A5D8(1, 4, 5, 0);
        entry = list->entries;
        offset = list->total_size;
        for (i = 0; i < list->count; entry++, i++) {
            if (entry->size != 0 &&
                (object->object_state[entry->object_index * 4] & 3) == 3) {
                fn_8022B448(offset, entry->size);
            }
            offset += entry->size;
        }
        entry = list->entries;
        for (i = 0; i < list->count; entry++, i++) {
            object->object_state[entry->object_index * 4] &= ~2;
        }
        object->state_flags &= ~0x00040000u;
    }
}
