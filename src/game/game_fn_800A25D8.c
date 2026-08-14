typedef struct Vec3i800A25D8 {
    int x;
    int y;
    int z;
} Vec3i800A25D8;

extern int fn_802045AC(void*, Vec3i800A25D8*);
extern float fn_8012B7D0(void*, Vec3i800A25D8*);
extern float fn_8012B750(void*);
extern void fn_8017A12C(float*, float, float);
extern void* fn_80128E30(void*);
extern void fn_80129BA4(void*, float, float);
extern int fn_801290D0(void*);
extern void fn_80128F74(void*, int);
extern float lbl_8064EE84;

void fn_800A25D8(void* object, void* resource)
{
    Vec3i800A25D8 position;
    Vec3i800A25D8 copy;
    float angle;
    float facing;
    int flags;

    if (fn_802045AC(object, &position)) {
        copy = position;
        facing = fn_8012B7D0(resource, &copy);
        fn_8017A12C(&angle, fn_8012B750(resource), facing);
        fn_80129BA4(fn_80128E30(resource), facing, lbl_8064EE84);
        flags = fn_801290D0(resource);
        fn_80128F74(resource, flags | 0x100);
    }
}
