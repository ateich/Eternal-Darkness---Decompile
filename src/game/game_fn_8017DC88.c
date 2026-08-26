typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

void fn_8017DC88(Vec3s* position, Vec3s* velocity, s16 acceleration)
{
    velocity->z -= acceleration;
    position->z += velocity->z;
}
