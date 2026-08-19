typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Vec3s {
    s16 x, y, z;
} Vec3s;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct EffectDescriptor {
    u8 variant;
    u8 mode;
    u8 pad02;
    s8 offset;
    u16 type;
    u8 pad06[0x12];
    u32 value18;
    u8 pad1C[0x74];
} EffectDescriptor;

extern const u32 lbl_8065191C;
extern const u16 lbl_80651920;

/* The second argument is ignored by the callee; retaining object_id in r4 keeps
 * MWCC's four-instruction constant copy in the retail r5/r0 register pair. */
extern void fn_80181F5C(EffectDescriptor*, s32);
extern void fn_80181FD8(void);
extern s32 fn_801D3A24(s32, s32);
extern void* fn_80148008(Vec3f*, const Vec3s*, EffectDescriptor*, void (*)(void));

void fn_80031C78(Vec3f* position, s32 object_id)
{
    Vec3s direction;
    Vec3f submit_position;
    EffectDescriptor effect;
    register EffectDescriptor* effect_ptr;
    register u16 direction_half;
    register u32 direction_word;

    /* Keep this small copy together after the prologue, as in retail. */
    asm {
        addi effect_ptr, r1, 0x1C
        lwz direction_word, lbl_8065191C(r0)
        lhz direction_half, lbl_80651920(r0)
        stw direction_word, direction
        sth direction_half, direction+4
    }
    fn_80181F5C(effect_ptr, object_id);
    effect.variant = 8;
    effect.mode = 4;
    effect.offset = -20;
    effect.value18 = 0;
    effect.type = fn_801D3A24(object_id, 0x31);

    submit_position = *position;
    fn_80148008(&submit_position, &direction, &effect, fn_80181FD8);
}
