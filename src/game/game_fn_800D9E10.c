typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Actor {
    u8 pad0[0x9C];
    void *effects[3];
} Actor;

typedef struct ShortVec {
    s16 x;
    s16 y;
    s16 z;
} ShortVec;

typedef struct Vec {
    float x;
    float y;
    float z;
} Vec;

extern void *fn_801A7498(void *);
extern void *fn_80201814(void *);
extern Actor *fn_800A1D28(void *);
extern ShortVec *fn_8017FDE4(void *);
extern void fn_801A75C0(Vec *, void *, int, Vec *);
extern void fn_801A7560(void *, int);

int fn_800D9E10(void *unused, void *object)
{
    int i;
    u32 target = (u32)object;
    Actor *actor = fn_800A1D28(fn_80201814(fn_801A7498((void *)target)));

    (void)unused;
    {
        for (i = 0; i < 4; i++) {
            void *effect = actor->effects[i % 3];
            if (effect != 0) {
                ShortVec *offset = fn_8017FDE4(effect);
                Vec input;
                Vec output;
                input.x = offset->x;
                input.y = offset->y;
                input.z = offset->z + 20;
                fn_801A75C0(&output, (void *)target, i, &input);
            }
        }
    }
    fn_801A7560((void *)target, 0x4000);
    return 1;
}
