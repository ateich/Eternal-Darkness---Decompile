typedef unsigned char u8;
typedef unsigned short u16;

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
extern int fn_800F5C54(double);
extern int fn_8015C4A4(int, int);
extern Vec3s* fn_80158ABC(int, int, void*);
extern float fn_80173B6C(short*, float*);
extern void fn_80154A98(Vec3*, Vec3s*, int, u16*, float);
extern const Vec3s lbl_806506E4;
extern const char lbl_8024FF00[];
extern const char lbl_8025009C[];

int fn_801739E8(void* state)
{
    int resource;
    float scale;
    u16 limits[2];
    int kind;
    int index;
    Vec3s* source;
    Vec3 position;
    Vec3s rotation;

    rotation = lbl_806506E4;

    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }

    resource = fn_800F5C54(fn_8016A694(state, 1));
    scale = fn_8016A694(state, 2);
    limits[0] = fn_8016A694(state, 3);
    limits[1] = fn_8016A694(state, 4);
    kind = fn_8016A694(state, 5);

    index = fn_8015C4A4(resource, 2);
    if (index != -1) {
        source = fn_80158ABC(index, 2, 0);
        fn_80173B6C(&source->x, &position.x);
        fn_80173B6C(&source->y, &position.y);
        fn_80173B6C(&source->z, &position.z);
    } else {
        fn_80163BB4(state, lbl_8025009C, resource);
    }

    fn_80154A98(&position, &rotation, kind, limits, scale);
    return 0;
}
