typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Data8008E294 {
    unsigned char pad0[0x10];
    int primary;
    int fallback;
} Data8008E294;

extern void* fn_8015C2FC(int);
extern int fn_80036D5C(void*);
extern void *fn_80201814();
extern void fn_80201E78(Vec3*, void*);
extern const float lbl_80239654[3];
extern u32 fn_80178E94(Vec3*, Vec3*);
extern int fn_800DE3F8(void);
extern void fn_80140E58(void);
extern u8 fn_80203F60(void*, void*, Vec3*, Vec3*, int);
extern int fn_8008E110(void*, void*, void*, Data8008E294*);
extern int fn_8008E078(void*, void*, void*);

/* NonMatching: behavior-complete frontier reconstruction; stack-local lifetime
 * and compound-condition codegen remain to be refined. */
int fn_8008E294(void* object, Data8008E294* data, void* resource,
                Vec3* position, void* argument)
{
    void* manager = fn_8015C2FC(2);
    int selected = data->primary;
    int flags;
    void* loaded;
    Vec3 target;
    u32 distance;

    if (selected == 0) {
        selected = data->fallback;
    }
    flags = fn_80036D5C(object) & 0x00100000;
    loaded = fn_80201814(selected);
    if (loaded != 0) {
        fn_80201E78(&target, loaded);
    } else {
        target.x = lbl_80239654[0];
        target.y = lbl_80239654[1];
        target.z = lbl_80239654[2];
    }
    distance = fn_80178E94(position, &target);
    if (loaded != 0 && flags == 0 && selected != fn_800DE3F8() &&
        distance < 500) {
        fn_80140E58();
        if (fn_80203F60(resource, manager, position, &target, 0) == 0) {
            return fn_8008E110(object, resource, argument, data);
        }
    }
    return fn_8008E078(object, resource, argument);
}
