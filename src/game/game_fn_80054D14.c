typedef signed int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float lbl_8064E4E8;

extern float fn_8012B750(void *object);
extern void fn_8011F114(void*, void*);
extern void fn_80054CA0(void *owner, void *object, s32 force);
extern void *fn_8013BAAC(void *context, void *object, float value);
extern void *fn_8013BE5C(void *context, void *object);
extern void fn_8011F0E8(void *object, Vec3 *position);
extern void fn_8012B7A0(void *object, float scale);

void *fn_80054D14(void *context, void *owner, void *object, s32 force)
{
    Vec3 restore;
    Vec3 current;
    void *result;
    float scale = fn_8012B750(object);

    fn_8011F114(&current, object);
    restore = current;
    fn_80054CA0(owner, object, force);

    result = fn_8013BAAC(context, object, lbl_8064E4E8);
    if (result == 0) {
        result = fn_8013BE5C(context, object);
    }

    fn_8011F0E8(object, &restore);
    fn_8012B7A0(object, scale);
    return result;
}
