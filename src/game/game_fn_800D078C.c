typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Target {
    char pad[0x68];
    void *handle;
} Target;

/* Honest C reconstruction; register allocation differs at the prologue. */

extern int fn_80201B54();
extern Target *fn_800A1D28(void *);
extern void fn_800D04A4(Vec3 *, void *);
extern void fn_800CA530(void);
extern void *fn_801D0814(int, int, int, Vec3 *, int, int, void *, int, Vec3 *);

void fn_800D078C(void *object, void *context)
{
    int id;
    Vec3 value;
    Vec3 position;

    id = fn_80201B54(context);
    context = fn_800A1D28(context);

    fn_800D04A4(&position, object);
    ((Target *)context)->handle = fn_801D0814(
        0x11041, 0, id, &value, 0, 0, fn_800CA530, (id << 8) | 0x78, &position);
}
