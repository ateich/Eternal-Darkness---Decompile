typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct SceneObject {
    u8 pad_00[0x44];
    float position[3];
    float scale;
    u8 pad_54[0x20];
    u32 resource;
} SceneObject;

typedef struct ObjectLink {
    SceneObject *object;
} ObjectLink;

extern void* fn_80201B8C();
extern void* fn_80201814();
extern void fn_8011F0E8(void *object, float *position);
extern void fn_8012B7A0(void *object, float scale);

void fn_80054CA0(void *owner, void *object, s32 force)
{
    SceneObject *source = ((ObjectLink *)fn_80201B8C(owner))->object;

    if (fn_80201814(source->resource) != 0 || force == 0) {
        fn_8011F0E8(object, source->position);
        fn_8012B7A0(object, source->scale);
    }
}
