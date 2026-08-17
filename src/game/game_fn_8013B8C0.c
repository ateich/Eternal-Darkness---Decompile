typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern Vec3* fn_8011F130(void*);
extern int fn_801A7E04(Vec3*, void*);
extern float lbl_80650300;

int fn_8013B8C0(void* object, void* other)
{
    Vec3* source;
    Vec3 position;

    source = fn_8011F130(object);
    position = *source;
    position.z += lbl_80650300;
    return fn_801A7E04(&position, other);
}
