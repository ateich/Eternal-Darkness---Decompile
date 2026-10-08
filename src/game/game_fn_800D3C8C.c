typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct ObjectState {
    u8 pad[0x68];
    void *effect;
} ObjectState;

typedef struct ObjectContext {
    u8 pad[0x64];
    ObjectState *state;
} ObjectContext;

extern float lbl_8064F3B8;
extern int fn_80201B54(void *object);
extern ObjectContext *fn_80201B8C(void *object);
extern void fn_8011F114(Vec3 *position, void *runtime);
extern int fn_800CA530(void *object);
extern void *fn_801D0814(u32 flags, u32 arg1, s32 subject, void *data,
                         u32 arg4, u32 arg5, u32 callback, u32 arg7,
                         s32 stack_arg);

void fn_800D3C8C(void *runtime, void *object)
{
    Vec3 data;
    Vec3 position;
    s32 object_id = fn_80201B54((void *)(u32)object);
    ObjectState *state = fn_80201B8C((void *)(u32)object)->state;

    fn_8011F114(&position, runtime);
    position.z += lbl_8064F3B8;
    state->effect = fn_801D0814(
        0x11042, 0, object_id, &data, 0, 0, (u32)fn_800CA530,
        (object_id << 8) | 0x78, (s32)&position);
}
