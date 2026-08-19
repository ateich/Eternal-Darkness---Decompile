typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct Vec3s {
    short x, y, z;
} Vec3s;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct EmbeddedDescriptor {
    u8 kind;
    u8 variant;
    u8 active;
    u8 pad03[3];
    u16 lifetime;
    u8 position08[6];
    u8 position0E[6];
    u8 pad14[0x10];
    u32 flags;
} EmbeddedDescriptor;

typedef struct EffectSlot {
    u8 pad00[0x14];
    EmbeddedDescriptor descriptor;
    u8 pad3C[0x80];
    u8 mode;
} EffectSlot;

typedef struct PrimarySlot {
    u8 pad00[0x14];
    EmbeddedDescriptor descriptor;
    u8 pad3C[0x4C];
} PrimarySlot;

extern const u32 lbl_80651924;
extern const u16 lbl_80651928;

extern void fn_801938FC(void*);
extern void fn_80179B64(void*, void*);
extern void fn_801D3CAC(s32, s32, EmbeddedDescriptor*);
extern void* fn_80148008(Vec3f*, const Vec3s*, PrimarySlot*, void (*)(void));
extern void fn_801936FC(void);
extern void *fn_80156938();
extern void fn_8017FF1C(void*, u8);
extern void* fn_80149E04(void);
extern void fn_80147E88(EffectSlot*);
extern void fn_80149FDC(EffectSlot*, void*);
extern u32 fn_80148300(void*, EffectSlot*, void*);
extern void fn_80149EB8(void*);

void* fn_80031D24(Vec3f* position_arg, void* source_arg, s32 object_id_arg,
                  s32 make_first_arg, s32 make_third_arg, u8 third_kind_arg,
                  u8 packed_kind_arg, u8 packed_variant_arg, u8 active_arg,
                  s32 extra_mode_arg)
{
    Vec3s direction;
    Vec3f submit_position;
    PrimarySlot primary;
    EffectSlot slot;
    register PrimarySlot* primary_ptr;
    register s32 make_third = make_third_arg;
    register s32 object_id = object_id_arg;
    register u8 active = active_arg;
    register EmbeddedDescriptor* descriptor;
    register Vec3f* position = position_arg;
    register s32 extra_mode = extra_mode_arg;
    register u8 packed_variant = packed_variant_arg;
    register u8 packed_kind = packed_kind_arg;
    register u8 third_kind = third_kind_arg;
    register s32 make_first = make_first_arg;
    register void* source = source_arg;
    void* result;
    void* spawned;
    void* setup;
    u8 failed;
    u8 mode;

    asm {
        addi primary_ptr, r1, 0xDC
        lwz r11, lbl_80651924(r0)
        lhz r0, lbl_80651928(r0)
        stw r11, 8(r1)
        sth r0, 0xC(r1)
    }
    fn_801938FC(primary_ptr);
    descriptor = &primary.descriptor;
    fn_80179B64(source, descriptor->position0E);
    descriptor->kind = packed_kind;
    descriptor->variant = packed_variant;
    descriptor->active = active;
    descriptor->flags |= 0x10;
    fn_801D3CAC(object_id, 0, descriptor);

    submit_position = *position;
    result = fn_80148008(&submit_position, &direction, &primary, fn_801936FC);
    if (result != 0) {
        failed = 0;
        mode = 4;
        setup = fn_80156938(result);
        if (extra_mode != 0) {
            mode |= 8;
        }
        fn_8017FF1C(setup, mode);

        if (make_first != 0) {
            spawned = fn_80149E04();
            if (spawned != 0) {
                fn_80147E88(&slot);
                fn_80149FDC(&slot, spawned);
                slot.mode = mode;
                fn_801938FC(&slot);
                slot.descriptor.lifetime = 200;
                slot.descriptor.kind = packed_kind >> 2;
                slot.descriptor.variant = packed_variant >> 1;
                slot.descriptor.flags |= 0x661;
                fn_801D3CAC(object_id, 0, &slot.descriptor);
                if (fn_80148300(result, &slot, spawned) == 0) {
                    fn_80149EB8(spawned);
                    failed = 1;
                }
            } else {
                failed = 1;
            }
        }

        if (third_kind != 0 && failed == 0) {
            spawned = fn_80149E04();
            if (spawned != 0) {
                fn_80147E88(&slot);
                fn_80149FDC(&slot, spawned);
                slot.mode = mode;
                *(u8*)spawned = third_kind;
                fn_801938FC(&slot);
                slot.descriptor.lifetime = 200;
                slot.descriptor.kind = packed_kind >> 2;
                slot.descriptor.variant = packed_variant >> 1;
                slot.descriptor.flags |= 0x362;
                fn_801D3CAC(object_id, 0, &slot.descriptor);
                if (fn_80148300(result, &slot, spawned) == 0) {
                    fn_80149EB8(spawned);
                    failed = 1;
                }
            } else {
                failed = 1;
            }
        }

        if (make_third != 0 && failed == 0) {
            spawned = fn_80149E04();
            if (spawned != 0) {
                fn_80147E88(&slot);
                fn_80149FDC(&slot, spawned);
                slot.mode = mode;
                fn_801938FC(&slot);
                slot.descriptor.lifetime = 200;
                slot.descriptor.kind = packed_kind >> 2;
                slot.descriptor.variant = packed_variant >> 1;
                slot.descriptor.flags |= 0x664;
                fn_801D3CAC(object_id, 0, &slot.descriptor);
                if (fn_80148300(result, &slot, spawned) == 0) {
                    fn_80149EB8(spawned);
                }
            }
        }
    }

    return result;
}
