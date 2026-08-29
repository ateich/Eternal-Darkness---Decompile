typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Particle {
    u8 pad_0[0xA];
    s16 x;
    s16 y;
    s16 z;
    s16 dx;
    s16 dy;
    s16 dz;
    u8 pad_16[0xB];
    u8 alpha;
    u8 pad_22[6];
    u32 colour0;
    u32 colour1;
    u32 colour2;
    u32 colour3;
} Particle;

typedef struct EffectState {
    u16 phase;
    u16 field_2;
    float field_4;
    float age;
    float step;
    u8 values[32];
    u8 field_30;
} EffectState;

extern float lbl_80650CA8;
extern float lbl_80650D10;
extern float lbl_80650D28;
extern float lbl_80650D2C;
extern float lbl_80650D30;
extern u32 lbl_80607440[];
extern int lbl_8064D18C;
extern void fn_801EF384(void*);
extern int fn_800FBFB0(void);
extern void fn_801A29E0(void*);

int fn_801A1F8C(u8* object)
{
    EffectState* state;
    Particle* particle;
    float scale;
    int count;
    int i;

    fn_801EF384(object);
    state = (EffectState*)(object + 0x8C);
    particle = *(Particle**)(object + 0x4C);
    scale = *(float*)(object + 0x90);
    count = object[1];

    if (*(float*)(object + 0x94) < scale) {
        scale = *(float*)(object + 0x94);
        state->age = *(float*)(object + 0x94) + state->step;
    }

    for (i = 0; i < count; i++, particle++) {
        int value;
        if ((state->phase ^ 1) != 0) {
            float t = scale;
            if (scale >= lbl_80650D10) {
                particle->x = particle->x + (s16)((particle->dx - particle->x) * t);
                particle->y = particle->y + (s16)((particle->dy - particle->y) * t);
                particle->z = particle->z + (s16)((particle->dz - particle->z) * t);
            } else {
                t = state->phase * scale;
                if (t >= lbl_80650D10) {
                    particle->x = particle->x + (s16)((particle->dx - particle->x) * t);
                    particle->y = particle->y + (s16)((particle->dy - particle->y) * t);
                    particle->z = particle->z + (s16)((particle->dz - particle->z) * t);
                }
            }
        }

        value = state->values[i] + (fn_800FBFB0() % 3) + 1;
        if (value > 255) {
            value = 255;
        }
        state->values[i] = value;
        particle->colour0 = lbl_80607440[state->values[i]];
        particle->colour1 = lbl_80607440[state->values[i]];
        particle->colour2 = lbl_80607440[state->values[i]];
        particle->colour3 = lbl_80607440[state->values[i]];
        particle->alpha = (u8)(lbl_80650D28 *
            (lbl_80650D2C + (lbl_80650CA8 - state->values[i]) / lbl_80650CA8) * scale);
    }

    state->phase++;
    particle = *(Particle**)(object + 0x4C);
    if (state->phase >= 4) {
        state->phase = 0;
        for (i = 0; i < count; i++, particle++) {
            int index = i + 0x10;
            if (state->values[index] == 255) {
                int random;
                random = fn_800FBFB0();
                particle->x = *(s16*)(object + 0x10) + scale * (10 - random % 20);
                random = fn_800FBFB0();
                particle->y = *(s16*)(object + 0x12) + scale * (10 - random % 20);
                particle->z = *(s16*)(object + 0x14);
                state->values[index] = 0;
                particle->dx = 1 - (fn_800FBFB0() & 1);
                particle->dy = 1 - (fn_800FBFB0() & 1);
                particle->dz = (fn_800FBFB0() & 1) + 1;
                particle->colour0 = lbl_80607440[0];
                particle->colour1 = lbl_80607440[0];
                particle->colour2 = lbl_80607440[0];
                particle->colour3 = lbl_80607440[0];
                particle->alpha = (u8)(lbl_80650D30 * scale);
                break;
            }
        }
    }

    (*(u16*)(object + 0xA))++;
    if (*(u16*)(object + 0xC) != 0 &&
        *(u16*)(object + 0xA) >= *(u16*)(object + 0xC)) {
        fn_801A29E0(object);
    }
    if (state->field_30 != 0 && lbl_8064D18C != *(int*)(object + 0x38)) {
        *(u16*)(object + 0x22) = 8;
    }
    return 0;
}
