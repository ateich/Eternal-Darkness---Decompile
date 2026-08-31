typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Effect {
    u8 pad0[0x50];
    Vec3 position;
    u8 pad5C[0x2D];
    u8 value89;
} Effect;

void fn_801AC59C(Effect* effect, const Vec3* position, u8 value, int flags)
{
    if (effect == 0) {
        return;
    }
    if (flags & 1) {
        effect->value89 = value;
    }
    if (!(flags & 2)) {
        return;
    }
    if (position == 0) {
        return;
    }
    effect->position.x = position->x;
    effect->position.y = position->y;
    effect->position.z = position->z;
}
