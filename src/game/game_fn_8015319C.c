typedef unsigned char u8;
typedef unsigned short u16;

typedef struct EffectDescriptor {
    u8 data[0xC8];
} EffectDescriptor;

extern void *fn_80201814();
extern void* fn_80155DB4(void);
extern void* fn_80149E04(void);
extern void fn_80147E88(EffectDescriptor*);
extern void fn_80153250(EffectDescriptor*, void*);
extern void fn_80149B0C(void*, void*, void*);
extern void* fn_80148300(void*, EffectDescriptor*, void*);
extern void fn_80149EB8(void*);

void fn_8015319C(void* owner, void* first, void* second, u8 kind, u16 value,
                 u8 mode, u8 variant)
{
    void* runtime;
    void* effect;
    EffectDescriptor descriptor;

    if (fn_80201814(owner) != 0) {
        runtime = fn_80155DB4();
        if (runtime != 0) {
            effect = fn_80149E04();
            if (effect != 0) {
                fn_80147E88(&descriptor);
                *(u16*)(descriptor.data + 6) = value;
                fn_80153250(&descriptor, effect);
                fn_80149B0C(effect, first, second);
                *((u8*)effect + 1) = kind;
                *((u8*)effect + 2) = mode;
                *((u8*)effect + 3) = variant;
                if (fn_80148300(runtime, &descriptor, effect) == 0) {
                    fn_80149EB8(effect);
                }
            }
        }
    }
}
