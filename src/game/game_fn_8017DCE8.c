typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

void fn_8017DCE8(Vec3f* position, Vec3f* velocity, float acceleration)
{
    velocity->z -= acceleration;
    position->x += velocity->x;
    position->y += velocity->y;
    position->z += velocity->z;
}
