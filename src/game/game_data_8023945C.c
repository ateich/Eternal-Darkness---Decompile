typedef unsigned int u32;

typedef struct EffectSpawnConstants {
    float scale[3];
    u32 resource_ids[10];
} EffectSpawnConstants;

/* Scale and resource identifiers used by the neighboring effect-spawn handler. */
const volatile EffectSpawnConstants lbl_8023945C = {
    {1.5f, 1.5f, 1.5f},
    {
        0x01020104,
        0x01030105,
        0x02820284,
        0x02830285,
        0x00000AF2,
        0x00000744,
        0x00000743,
        0x00000570,
        0x00000081,
        0x00000A6F,
    },
};
