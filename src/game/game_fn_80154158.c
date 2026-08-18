typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern void fn_801A1BD0(void);
extern void* fn_80148008(Vec3f*, void*, void*, void (*)(void));
extern void* fn_80156938(void*);
extern void fn_8017FF1C(void*, int);

void* fn_80154158(Vec3f* position, void* resource, void* descriptor)
{
    Vec3f copy = *position;
    void* result = fn_80148008(&copy, resource, descriptor, fn_801A1BD0);
    if (result != 0)
        fn_8017FF1C(fn_80156938(result), 0x84);
    return result;
}
