typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Segment {
    unsigned char bytes[0x40];
} Segment;

typedef struct Hit {
    unsigned char bytes[0x18];
} Hit;

extern float lbl_8064E200;
extern float lbl_8064E204;

extern void* fn_8012AB2C(void*);
extern void fn_8013F3C0(Segment*, Vec3*, Vec3*, float);
extern void* fn_8013FBE4(void*, Segment*, Hit*, s32, s32);

s32 fn_80035890(void* unused0, void* unused1, void* owner,
                register Vec3* start, register Vec3* end)
{
    register void* world;
    register s32 clear;
    Segment segment;
    Hit hit;
    float adjustment;
    float value;
    float width;

    clear = 1;
    world = fn_8012AB2C(owner);
    value = start->z;
    adjustment = lbl_8064E200;
    width = lbl_8064E204;
    start->z = value + adjustment;
    value = end->z;
    end->z = value + adjustment;
    fn_8013F3C0(&segment, start, end, width);
    if (fn_8013FBE4(world, &segment, &hit, 0, 9) != 0) {
        clear = 0;
    }
    value = start->z;
    adjustment = lbl_8064E200;
    start->z = value - adjustment;
    value = end->z;
    end->z = value - adjustment;
    return clear;
}
