typedef unsigned short u16;
typedef unsigned int u32;

typedef struct EffectData {
    u16 resource[40];
    u16 point[3][5][2];
    u16 delay[3][5];
    u16 pad_AA;
    u16 age[3][5];
    u16 pad_CA;
    u32 color[3];
} EffectData;

/* Particle-effect resource descriptor and per-variant runtime defaults. */
#pragma force_active on
EffectData lbl_8023DEB0 = {
    {
        0x0000, 0x0200, 0x01F0, 0x0200, 0x01F0, 0x0108, 0x0000, 0x0108,
        0x0000, 0x0100, 0x01F0, 0x0100, 0x01F0, 0x0008, 0x0000, 0x0008,
        0x0000, 0x016A, 0x0000, 0x016A, 0x0000, 0x016A, 0x0000, 0x016A,
        0x0000, 0x016A, 0x0200, 0x016A, 0x0200, 0x00C0, 0x0000, 0x00C0,
        0x0000, 0x016A, 0x0400, 0x016A, 0x0400, 0x0015, 0x0000, 0x0015,
    },
    {{{0}}},
    {{0}},
    0,
    {
        {12, 12, 12, 12, 12},
        {12, 12, 12, 12, 12},
        {12, 12, 12, 12, 12},
    },
    0,
    {0xFF6464FF, 0xC8FF80FF, 0xAFAFFFFF},
};
#pragma force_active reset
