typedef unsigned int u32;
typedef unsigned short u16;

typedef struct GameEffectDescriptor {
    u32 flags;
    u32 lifetime;
    u16 extent;
    u16 reserved;
    float scale[3];
    float velocity[3];
    float color[3];
    float offset[3];
} GameEffectDescriptor;

/* Tuned effect descriptor with uniform scale, velocity and color vectors. */
const volatile GameEffectDescriptor lbl_802396F0 = {
    0,
    40,
    40,
    0,
    { 1.0f, 1.0f, 1.0f },
    { -0.005f, -0.005f, -0.005f },
    { 0.2f, 0.2f, 0.2f },
    { 0.0f, 0.0f, 0.0f },
};
