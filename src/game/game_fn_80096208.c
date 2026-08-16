typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct State80096208 {
    u8 pad00[0x28];
    void* object;
    u32 flags;
} State80096208;

extern void* lbl_8064C6F8;
extern const float lbl_8064EC7C;
extern const float lbl_8064ECE0;
extern const float lbl_8064ECE4;

extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011F114();
extern float fn_8012B7D0(void*, Vec3*);
extern float fn_8012B750(void*);
extern void fn_8017A12C(float*, float, float);
extern void fn_800BE86C(void*, Vec3*, int, int, float);
extern void* fn_801294DC(void*, int, int, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_80096208(register void* object, register void* resource, void* unused,
                register State80096208* state, register int use_direction)
{
    register void* owner;
    register float first;
    Vec3 position;

    owner = fn_80201BC8(fn_80201814(state->object));
    fn_8011F114(&position, owner);
    if (use_direction != 0) {
        Vec3 copy = position;
        float angle;
        float magnitude;
        first = fn_8012B7D0(resource, &copy);
        fn_8017A12C(&angle, fn_8012B750(resource), first);
        magnitude = angle;
        if (magnitude < lbl_8064EC7C) {
            magnitude = -magnitude;
        }
        if (magnitude > lbl_8064ECE0) {
            fn_800BE86C(resource, &position, 2, 0, lbl_8064ECE4);
        } else {
            fn_801294DC(resource, 0xF, 0x25, 1);
        }
    }
    if ((state->flags & 2) == 0 && lbl_8064C6F8 == 0) {
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
    return 1;
}
