typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54();
extern void fn_801D6FEC(s32, Vec3f*, f32);

s32 fn_80018EF4(void* script)
{
    s32 type;
    s32 flags;
    s32 extra;
    Vec3s* packed;
    Vec3f position;
    f32 value;

    flags = 0x410;
    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    type = fn_800F5C54(fn_8016A694(script, 1));
    extra = fn_800F5C54(fn_8016A694(script, 2));
    packed = fn_8016A784(script, 3);
    value = (f32)fn_8016A694(script, 4);

    switch (type) {
    case 1:
        flags |= 1;
        break;
    case 2:
        flags |= 2;
        break;
    case 3:
        flags |= 4;
        break;
    case 4:
        flags |= 8;
        break;
    }

    flags |= extra;
    position.x = packed->x;
    position.y = packed->y;
    position.z = packed->z;
    fn_801D6FEC(flags, &position, value);
    return 0;
}
