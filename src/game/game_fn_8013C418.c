typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

float fn_8013C418(const Vec3* origin, const Vec3* point,
                  const Vec3* direction, Vec3* output)
{
    float amount;

    amount = (origin->x - point->x) * direction->x
           + (origin->y - point->y) * direction->y
           + (origin->z - point->z) * direction->z;
    output->x = point->x + amount * direction->x;
    output->y = point->y + amount * direction->y;
    output->z = point->z + amount * direction->z;
    return amount;
}
