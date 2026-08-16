typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct TransformSource {
    u8 pad0[4];
    u32 scale;
    Vec3 first;
    Vec3 second;
    Vec3 third;
} TransformSource;

typedef struct RuntimeState {
    u8 pad[0x10];
    TransformSource *transform;
} RuntimeState;

extern void *fn_80201B8C();
extern void fn_801E7BF0(Vec3 *, Vec3 *, Vec3 *, u32 *);
extern void fn_801ECC4C(void);

void fn_800CF03C(void *object)
{
    TransformSource *source = ((RuntimeState *)fn_80201B8C(object))->transform;
    u32 scale;
    Vec3 first;
    Vec3 second;
    Vec3 third;

    scale = source->scale;
    third = source->third;
    second = source->second;
    first = source->first;

    fn_801E7BF0(&first, &second, &third, &scale);
    fn_801ECC4C();
}
