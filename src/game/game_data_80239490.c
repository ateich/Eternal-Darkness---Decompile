typedef unsigned short u16;
typedef unsigned int u32;

typedef struct PackedPair {
    u16 first;
    u16 second;
} PackedPair;

typedef struct EffectParameterTable {
    float scalar_parameters[12];
    float direction_vectors[4][3];
    PackedPair timing_parameters[8];
    u32 selectors[3];
    PackedPair range_parameters[5];
} EffectParameterTable;

/* Scalar, direction, timing, selector, and range parameters for the effect. */
const volatile EffectParameterTable lbl_80239490 = {
    {
        65.0f, 700.0f, 80.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
    },
    {
        {-32.0f, 32.0f, 0.0f},
        {32.0f, 32.0f, 0.0f},
        {32.0f, -32.0f, 0.0f},
        {-32.0f, -32.0f, 0.0f},
    },
    {
        {0x00E8, 0x00A2},
        {0x0109, 0x0090},
        {0x0128, 0x0085},
        {0x014A, 0x0099},
        {0x016A, 0x0000},
        {0x018A, 0x0000},
        {0x01AC, 0x0000},
        {0x0000, 0x0000},
    },
    {3, 1, 2},
    {
        {0x0064, 0x0046},
        {0x00C8, 0x0032},
        {0x012C, 0x0046},
        {0x0190, 0x0032},
        {0x01F4, 0x0046},
    },
};
