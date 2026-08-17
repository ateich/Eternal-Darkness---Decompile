typedef unsigned char u8;
typedef float Vec3[3];

typedef struct Override {
    unsigned words[4];
} Override;

typedef struct Owner {
    u8 pad0[0x154];
    Vec3* vectors;
    Override* overrides;
    u8 pad15C[0x14C];
    u8* flags;
} Owner;

extern void fn_801270DC(Vec3, const Vec3);

void fn_80128058(Owner* owner, int index, const Override* override,
                 const Vec3 vector)
{
    owner->flags[index] = 0;
    if (override != 0) {
        owner->overrides[index] = *override;
        owner->flags[index] |= 1;
    }
    if (vector != 0) {
        fn_801270DC(owner->vectors[index], vector);
        owner->flags[index] |= 2;
    }
}
