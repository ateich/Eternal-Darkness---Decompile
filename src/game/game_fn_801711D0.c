typedef signed short s16;
typedef unsigned char u8;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern int fn_8015C4A4(int, int);
extern Vec3s* fn_80158ABC(int, int, void*);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern u8 fn_8012B8A8(void*, const Vec3f*);
extern void fn_8016A830(void*, double);
extern void fn_8016A970(void*, void*, int);
extern const char lbl_8024FF00[];
extern const double lbl_806506A8;

int fn_801711D0(void* state)
{
    register const char* strings = lbl_8024FF00;
    int object_id;
    void* object;
    int handle;
    int index;
    Vec3s* packed;
    Vec3f position;
    u8 result;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, strings, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    object = fn_80201814(object_id);
    if (object != 0) {
        handle = fn_800F5C54(fn_8016A694(state, 2));
        index = fn_8015C4A4(handle, 2);
        if (index != -1) {
            packed = fn_80158ABC(index, 2, &result);
            position.x = packed->x;
            position.y = packed->y;
            position.z = packed->z;
            object = fn_80201BC8(object);
            fn_8016A830(state, (int)fn_8012B8A8(object, &position));
        } else {
            fn_80163BB4(state, strings + 412, handle);
            fn_8016A970(state, 0, 0);
        }
    } else {
        fn_80163BB4(state, strings + 796, object_id);
        fn_8016A970(state, 0, 0);
    }
    return 1;
}
