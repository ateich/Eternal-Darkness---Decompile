typedef unsigned char u8;

typedef struct Vec3s { short x, y, z; } Vec3s;
typedef struct Vec3f { float x, y, z; } Vec3f;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern int fn_8015C4A4(int, int);
extern Vec3s* fn_80158CC8(int, int, Vec3s*);
extern void fn_80179904(Vec3s*, short);
extern void fn_801533A8(Vec3f*, Vec3s*, int, int, int, int, int);
extern const char lbl_8024FF00[];
extern const char lbl_8025009C[];

int fn_80174184(void* state)
{
    int resource;
    int arg7;
    int arg2;
    int arg3;
    int arg4;
    int arg5;
    int arg6;
    int index;
    Vec3s lookup;
    Vec3s* source;
    Vec3f position;

    if (fn_8016A598(state) != 7) {
        fn_80163BB4(state, lbl_8024FF00, 7, fn_8016A598(state));
        return 0;
    }

    resource = fn_800F5C54(fn_8016A694(state, 1));
    arg2 = fn_8016A694(state, 2);
    arg3 = fn_8016A694(state, 3);
    arg4 = fn_8016A694(state, 4);
    arg5 = fn_8016A694(state, 5);
    arg6 = fn_8016A694(state, 6);
    arg7 = fn_8016A694(state, 7);

    index = fn_8015C4A4(resource, 2);
    if (index != -1) {
        source = fn_80158CC8(index, 2, &lookup);
    } else {
        fn_80163BB4(state, lbl_8025009C, resource);
    }

    /* Retail intentionally falls through with source and lookup uninitialized
     * when the lookup above returns -1. Preserve that matching behavior. */
    position.x = source->x;
    position.y = source->y;
    position.z = source->z;
    fn_80179904(&lookup, (short)arg7);
    fn_801533A8(&position, &lookup, arg2, arg3, arg5, arg4, arg6);
    return 0;
}
