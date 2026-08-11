typedef signed int s32;
typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u8 lbl_8063CD18[];
extern u8 lbl_8063C6B8[];

extern float fn_8012B750(void *object);
extern void fn_8011F114(Vec3 *position, void *object);
extern void fn_80054CA0(void *owner, void *object, s32 force);
extern void fn_801F8748(void *context, void *object, s32 arg2, s32 arg3, s32 arg4);
extern void fn_801F6FFC(void *object);
extern void fn_8011F0E8(void *object, Vec3 *position);
extern void fn_8012B7A0(void *object, float scale);

void fn_80054DF4(void *context, void *owner, void *object, s32 force)
{
    Vec3 restore;
    Vec3 current;
    float scale = fn_8012B750(object);

    fn_8011F114(&current, object);
    restore = current;
    fn_80054CA0(owner, object, force);
    fn_801F8748(context, object, 0, 0, 0);
    fn_801F6FFC(lbl_8063CD18 + 0x198);
    fn_801F6FFC(lbl_8063C6B8 + 0x198);
    fn_8011F0E8(object, &restore);
    fn_8012B7A0(object, scale);
}
