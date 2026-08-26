typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

#define MIN(a, b) ((b) < (a) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(value, low, high) MIN(MAX((value), (low)), (high))

void fn_8017D908(Vec3s* position, Vec3s* target, Vec3s* velocity,
                 s16 xy_speed, s16 z_acceleration, s16 z_speed)
{
    s16 dz;

    dz = target->z - position->z;
    dz = CLAMP(dz, -z_acceleration, z_acceleration);

    velocity->x = target->x - position->x;
    velocity->y = target->y - position->y;
    velocity->z += dz;

    velocity->x = CLAMP(velocity->x, -xy_speed, xy_speed);
    velocity->y = CLAMP(velocity->y, -xy_speed, xy_speed);
    velocity->z = CLAMP(velocity->z, -z_speed, z_speed);

    position->x += velocity->x;
    position->y += velocity->y;
    position->z += velocity->z;
}
