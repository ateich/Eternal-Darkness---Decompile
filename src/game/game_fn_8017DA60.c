typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

#define MIN(a, b) ((b) < (a) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(value, low, high) MIN(MAX((value), (low)), (high))

void fn_8017DA60(Vec3s* position, Vec3s* target, Vec3s* velocity, s16 speed)
{
    velocity->x = target->x - position->x;
    velocity->y = target->y - position->y;
    velocity->z = target->z - position->z;

    velocity->x = CLAMP(velocity->x, -speed, speed);
    velocity->y = CLAMP(velocity->y, -speed, speed);
    velocity->z = CLAMP(velocity->z, -speed, speed);

    position->x += velocity->x;
    position->y += velocity->y;
    position->z += velocity->z;
}
