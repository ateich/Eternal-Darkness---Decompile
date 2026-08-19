typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3_800A32B8 {
    float x;
    float y;
    float z;
} Vec3_800A32B8;

typedef struct EffectParams800A32B8 {
    u8 pad0[2];
    u8 value2;
    signed char value3;
    u8 pad4[2];
    u16 value6;
    u8 pad8[0xC];
    u8 value14;
    u8 value15;
    u8 value16;
    u8 value17;
    u8 value18;
    u8 value19;
    u8 pad1A[0x76];
} EffectParams800A32B8;

extern u32 lbl_80651A20;
extern u16 lbl_80651A24;
extern float lbl_8064EEA0;
extern void fn_8018358C(EffectParams800A32B8*);
extern void fn_801833B8(void);
extern void* fn_80148008(Vec3_800A32B8*, void*, EffectParams800A32B8*,
                         void (*)(void));
extern void *fn_80156938();
extern void fn_8017FF1C(void*, int);

/*
 * Behavior-complete, size-equal reconstruction. The only current divergence
 * is MWCC scheduling the lbl_8064EEA0 load after the saved-register and
 * descriptor stores instead of directly after mflr. Objdiff: 76.666664%,
 * 240/240 bytes; all nine relocations have equal targets and types.
 */
void fn_800A32B8(const Vec3_800A32B8* source)
{
    struct {
        u32 word;
        u16 half;
    } descriptor;
    Vec3_800A32B8 position;
    Vec3_800A32B8 effect_position;
    EffectParams800A32B8 params;
    void* effect;
    float zero = lbl_8064EEA0;

    descriptor.word = lbl_80651A20;
    descriptor.half = lbl_80651A24;
    position = *source;
    position.z = zero;
    fn_8018358C(&params);
    params.value16 = 250;
    params.value2 = 250;
    params.value3 = -5;
    params.value6 = 60;
    params.value17 = 5;
    params.value18 = 1;
    params.value14 = 10;
    params.value15 = 250;
    params.value19 = 2;
    effect_position = position;
    effect = fn_80148008(&effect_position, &descriptor, &params, fn_801833B8);
    if (effect != 0) {
        fn_8017FF1C(fn_80156938(effect), 4);
    }
}
