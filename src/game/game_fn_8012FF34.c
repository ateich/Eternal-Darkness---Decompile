typedef unsigned char u8;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct RuntimeState {
    Vec3 position;
    u8 pad0C[0x34];
    float scale;
    int state;
    u8 pad48[0xC];
    u8 flags;
    u8 index;
} RuntimeState;

typedef struct Object {
    u8 pad[0x290];
    RuntimeState* runtime;
} Object;

extern float lbl_806501DC;
extern void fn_80125ECC(void*);
extern int fn_8012FFE0(void*, int, int);

void fn_8012FF34(Object* object, Vec3* position, int flags, int index)
{
    float one;

    fn_80125ECC(object);
    if (fn_8012FFE0(object, flags, index)) {
        one = lbl_806501DC;
        object->runtime->position = *position;
        object->runtime->flags = flags;
        object->runtime->state = 2;
        object->runtime->index = index;
        object->runtime->scale = one;
    }
}
