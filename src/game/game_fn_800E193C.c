typedef struct Vec3 { float x, y, z; } Vec3;

extern int fn_80201B44();
extern void* fn_80201B3C();
extern void fn_80201E78(Vec3 *, void *);
extern void fn_80179064(int, int, int, int);

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
