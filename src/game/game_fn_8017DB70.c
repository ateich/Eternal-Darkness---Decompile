typedef signed short s16;
typedef unsigned char u8;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct Vec3u8 {
    u8 x;
    u8 y;
    u8 z;
} Vec3u8;

#define MIN(a, b) ((b) < (a) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(value, low, high) MIN(MAX((value), (low)), (high))

void fn_8017DB70(Vec3s* position, Vec3s* target, Vec3s* velocity, Vec3u8* speed)
{
    velocity->x = target->x - position->x;
    velocity->y = target->y - position->y;
    velocity->z = target->z - position->z;

    velocity->x = CLAMP(velocity->x, -speed->x, speed->x);
    velocity->y = CLAMP(velocity->y, -speed->y, speed->y);
    velocity->z = CLAMP(velocity->z, -speed->z, speed->z);

    position->x += velocity->x;
    position->y += velocity->y;
    position->z += velocity->z;
}
