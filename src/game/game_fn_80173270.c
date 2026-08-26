typedef struct Vec3s {
    short x;
    short y;
    short z;
} Vec3s;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern int fn_8015C4A4(int, int);
extern Vec3s* fn_80158CC8(int, int, Vec3s*);
extern void fn_801798DC(Vec3*, float);
extern void fn_8014D478(void*, Vec3*, Vec3*, int, int, void*, int);
extern int lbl_806506E0;
extern const double lbl_806506A8;
extern const char lbl_8024FF00[];
extern const char lbl_8025009C[];

int fn_80173270(void* state)
{
    int resource;
    int arg2;
    int arg3;
    short arg8;
    int arg9;
    int index;
    Vec3s lookup;
    Vec3s* source;
    Vec3 position;
    Vec3 rotation;
    int effect = lbl_806506E0;

    if (fn_8016A598(state) != 9) {
        fn_80163BB4(state, lbl_8024FF00, 9, fn_8016A598(state));
        return 0;
    }

    resource = fn_800F5C54(fn_8016A694(state, 1));
    arg2 = fn_8016A694(state, 2);
    arg3 = fn_8016A694(state, 3);
    fn_8016A694(state, 4);
    fn_8016A694(state, 5);
    fn_8016A694(state, 6);
    fn_8016A694(state, 7);
    arg8 = fn_8016A694(state, 8);
    arg9 = fn_8016A694(state, 9);

    index = fn_8015C4A4(resource, 2);
    if (index != -1) {
        source = fn_80158CC8(index, 2, &lookup);
    } else {
        fn_80163BB4(state, lbl_8025009C, resource);
    }

    position.x = source->x;
    position.y = source->y;
    position.z = source->z;
    rotation.x = lookup.x;
    rotation.y = lookup.y;
    rotation.z = lookup.z;
    fn_801798DC(&rotation, arg8);
    fn_8014D478(0, &position, &rotation, arg2, arg3, &effect, arg9);
    return 0;
}
