typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Slot {
    void* owner;
    u32 capacity;
    void* data;
    u32 field_C;
    u32 field_10;
    u16 field_14;
    u8 state;
} Slot;

typedef struct Pair { u16 count; u16 pad; void* data; } Pair;
typedef struct Object {
    void* records;
    u16 record_count;
    char pad_6[0xA];
    u32 counts[32];
    void* arrays[32];
    char pad_110[4];
    void* base;
    u32 source;
    u32 size;
    Slot* slot;
} Object;

typedef struct Manager { char pad_0[0x244]; u32 tag; } Manager;

extern Slot* fn_80134F7C(Object*);
extern char* fn_8013523C(Manager*, Object*);

/* NonMatching: honest reconstruction of the file-image fixups and array
 * partitioning. Retail unrolls the second loop four fields at a time. */
Slot* fn_8013507C(Manager* manager, Object* object)
{
    Slot* slot = fn_80134F7C(object);
    char* image;
    int i;
    slot->state = 4;
    object->slot = slot;
    slot->field_14 = manager->tag;
    slot->owner = object;
    slot->field_C = object->source;
    slot->field_10 = object->size;
    image = fn_8013523C(manager, object);
    object->base = image + *(u32*)image;
    object->records = image + *(u32*)(image + 8);
    for (i = 0; i < object->record_count; i++) {
        Pair* p = (Pair*)((char*)object->records + i * 16);
        Pair* q = (Pair*)((char*)p + 8);
        p->data = p->count ? image + (u32)p->data : 0;
        q->data = q->count ? image + (u32)q->data : 0;
    }
    image += *(u32*)(image + 12);
    for (i = 0; i < 32; i++) {
        object->arrays[i] = object->counts[i] ? image : 0;
        image += object->counts[i] * 8;
    }
    return slot;
}
