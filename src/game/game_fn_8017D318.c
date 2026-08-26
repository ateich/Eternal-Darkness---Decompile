typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

#define MIN(a, b) ((b) < (a) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(value, low, high) MIN(MAX((value), (low)), (high))

void fn_8017D318(Vec3s* position, Vec3s* target, s16 z_offset,
                 Vec3s* velocity, s16 acceleration, s16 speed)
{
    s16 dx = target->x - position->x;
    s16 dz = target->z - position->z - z_offset;
    s16 dy = target->y - position->y;

    dx = CLAMP(dx, -acceleration, acceleration);
    dy = CLAMP(dy, -acceleration, acceleration);
    dz = CLAMP(dz, -acceleration, acceleration);

    velocity->x += dx;
    velocity->y += dy;
    velocity->z += dz;

    velocity->x = CLAMP(velocity->x, -speed, speed);
    velocity->y = CLAMP(velocity->y, -speed, speed);
    velocity->z = CLAMP(velocity->z, -speed, speed);

    position->x += velocity->x;
    position->y += velocity->y;
    position->z += velocity->z;
}
