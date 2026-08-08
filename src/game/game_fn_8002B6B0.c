typedef short s16;
typedef unsigned int u32;

typedef struct S16Vec3 {
    s16 x;
    s16 y;
    s16 z;
} S16Vec3;

typedef struct Object {
    unsigned char pad[0x14];
    volatile S16Vec3 position;
} Object;

extern u32 lbl_8064E030;
extern void fn_80179904(S16Vec3*, int);
extern void fn_80153050(Object*, S16Vec3*, int, int, int, int, u32*, int,
                        int, int, int, int);

void fn_8002B6B0(Object* object)
{
    u32 value = lbl_8064E030;
    S16Vec3 position;

    position.x = object->position.x;
    position.y = object->position.y;
    position.z = object->position.z;

    fn_80179904(&position, 1);
    fn_80153050(object, &position, 10, 4, 10, 10, &value, 1,
                5, -1, 1, 200);
}
