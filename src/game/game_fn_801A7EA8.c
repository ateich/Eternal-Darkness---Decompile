typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec3s {
    short x;
    short y;
    short z;
} Vec3s;

typedef struct Shape801A7EA8 {
    unsigned int radius;
    Vec3s center;
    unsigned char padA[0x32];
    short type;
} Shape801A7EA8;

typedef struct Object801A7EA8 {
    unsigned char pad[0x30];
    Shape801A7EA8 shape;
} Object801A7EA8;

extern void fn_80179DB0(Vec3*, Vec3s*);
extern int fn_8013D828(const Vec3*, const Vec3*, float);
extern int fn_8013D7A8(const Vec3*, const Vec3s*, const Vec3s*, Vec3*);

int fn_801A7EA8(const Vec3* point, Object801A7EA8* object)
{
    Shape801A7EA8* shape = &object->shape;
    short type = shape->type;

    if (type == 0) {
        Vec3 center;
        fn_80179DB0(&center, &shape->center);
        return fn_8013D828(point, &center, (float)shape->radius);
    }
    if (type == 1) {
        Vec3 result;
        return fn_8013D7A8(point, (Vec3s*)shape,
                           (Vec3s*)((unsigned char*)shape + 6), &result);
    }
    return 0;
}
