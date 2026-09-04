typedef unsigned char u8;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Target Target;
typedef struct Voice Voice;
extern float lbl_80650FB0;
extern int fn_801C970C(Voice*, Vec3*, Vec3*, Vec3*, float, float, float, float,
                      Vec3*, void*, u8, Target*);

int fn_801C9914(Voice* voice, Vec3* position, Vec3* velocity, Vec3* direction,
                float a, float b, float c, Vec3* up, void* data, u8 level,
                Target* target)
{
    return fn_801C970C(voice, position, velocity, direction, a, b, c,
                       lbl_80650FB0, up, data, level, target);
}
