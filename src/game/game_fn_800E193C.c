typedef struct Vec3 { float x, y, z; } Vec3;

extern int fn_80201B44();
extern void* fn_80201B3C();
#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS Vec3 *, void *
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern void fn_80179064(int, int, int, int);

void fn_800E193C(void *object)
{
    Vec3 first;
    Vec3 second;
    void *other;

    fn_80201B44();
    other = fn_80201B3C();
    fn_80201E78(&first, object);
    fn_80201E78(&second, other);
    fn_80179064((int)first.x, (int)first.y, (int)second.x, (int)second.y);
}
