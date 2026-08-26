typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

void fn_8017DCA8(Vec3s* position, s16 acceleration, Vec3s* velocity)
{
    velocity->z -= acceleration;
    position->x += velocity->x;
    position->y += velocity->y;
    position->z += velocity->z;
}
