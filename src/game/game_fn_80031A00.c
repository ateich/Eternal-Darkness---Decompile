typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct QueryResult {
    u8 data[0x28];
} QueryResult;

typedef struct EmbeddedDescriptor {
    u8 kind;
    u8 variant;
    u8 active;
    u8 pad03[5];
    u8 position08[6];
    u8 position0E[6];
    u8 pad14[0x10];
    u32 flags;
} EmbeddedDescriptor;

typedef struct EffectSlot {
    u8 pad00[0x14];
    EmbeddedDescriptor descriptor;
    u8 pad3C[0x6C];
    u32 owner;
    u8 padAC[0x10];
    u8 mode;
    u8 padBD;
    u8 alpha;
    u8 padBF;
    void* spawned;
} EffectSlot;
extern void *fn_80201814();
extern void *fn_80201BC8();
extern s32 fn_8011F6A4(void*, s32, s32, s32, QueryResult*, s32);
extern void* fn_80149E04(void);
extern void fn_80147E88(EffectSlot*);
extern void fn_8014A1E4(EffectSlot*, void*);
extern void fn_8014A314(EffectSlot*, void*);
extern void fn_80149B0C(void*, s32, s32);
extern void fn_801938FC(EffectSlot*);
extern void fn_801D3CAC(s32, s32, EmbeddedDescriptor*);
extern void fn_80179B64(void*, void*);
extern void* fn_80155DB4(void*);
extern u32 fn_80148300(void*, EffectSlot*, void*);
extern void fn_80149EB8(void*);

void fn_80031A00(u8 mode, EffectSlot* slot, s32 object_id, void* position,
                 s32 owner, s32 query_a, s32 query_b, u8 kind, u8 variant,
                 s32 extra_flags, s32 extra_mode)
{
    QueryResult query;
    void* object;
    void* manager;
    EmbeddedDescriptor* descriptor;

    object = fn_80201814(owner);
    if (object == 0) {
        return;
    }

    manager = fn_80201BC8();
    if (manager == 0) {
        return;
    }

    if (fn_8011F6A4(manager, query_a, query_b, -1, &query, 1) == -1) {
        return;
    }

    slot->spawned = fn_80149E04();
    if (slot->spawned == 0) {
        return;
    }

    fn_80147E88(slot);
    if (mode == 0 || mode == 2) {
        fn_8014A1E4(slot, slot->spawned);
    } else {
        fn_8014A314(slot, slot->spawned);
    }

    slot->mode = 4;
    if (extra_mode != 0) {
        slot->mode |= 8;
    }

    fn_80149B0C(slot->spawned, query_a, query_b);
    slot->owner = owner;
    fn_801938FC(slot);

    descriptor = &slot->descriptor;
    descriptor->kind = kind;
    descriptor->variant = variant;
    fn_801D3CAC(object_id, 0, descriptor);
    descriptor->flags |= 0x440;
    if (extra_flags != 0) {
        descriptor->flags |= 0x4000;
    }
    if (mode == 0 || mode == 1) {
        descriptor->flags |= 0x10;
    }

    if (mode == 0 || mode == 2) {
        fn_80179B64(position, descriptor->position0E);
    } else {
        u32 flags;

        fn_80179B64(position, descriptor->position08);
        flags = descriptor->flags;
        flags |= 0x40000;
        descriptor->flags = flags;
    }
    descriptor->active = 1;

    manager = fn_80155DB4(object);
    if (manager == 0) {
        return;
    }

    slot->alpha = 0x80;
    if (fn_80148300(manager, slot, slot->spawned) == 0) {
        fn_80149EB8(slot->spawned);
        slot->spawned = 0;
    }
}
