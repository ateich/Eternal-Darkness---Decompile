typedef struct Vec3 { float x, y, z; } Vec3;
typedef unsigned char u8;
typedef unsigned int u32;

extern void* fn_80201B94();
extern void fn_8011F114();
extern void fn_802045AC(void*, Vec3*);
extern int fn_80178E94(Vec3*, Vec3*);
extern int fn_800BE2CC(void*, void*, Vec3*);
extern void fn_800BE390(void*, void*);
extern int fn_8012AFC4(void*);
#define FN_80128E30_RETURN void*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern void fn_80128C3C(void*, float);
extern void fn_80129928(void*, Vec3*);
extern void fn_8012976C(void*, void*, int, Vec3*, float);
extern int fn_8011EB04(void*);
extern const float lbl_8064EC9C;

int fn_8009A2B8(register void* object, register void* action, void* unused,
                register u8* actor, void* unused2, register void* arg,
                register u32 distance, register int flags, float speed)
{
    register int result = 0;
    Vec3 object_pos;
    Vec3 action_pos;
    Vec3 target_pos;

    fn_80201B94(object);
    fn_8011F114(&action_pos, action);
    fn_802045AC(object, &object_pos);
    if ((flags & 1) != 0 && (signed char)actor[0x163] != 0) {
        actor[0x163] = 0;
        speed = lbl_8064EC9C;
    }
    if (fn_80178E94(&action_pos, &object_pos) < (int)distance) {
        result = 1;
    } else if (fn_800BE2CC(object, actor, &target_pos) != 0) {
        if ((u32)fn_80178E94(&action_pos, &target_pos) < distance) {
            fn_800BE390(object, actor);
        } else if (fn_8012AFC4(action) != 0) {
            fn_80128C3C(fn_80128E30(action), speed);
            fn_80129928(action, &target_pos);
        } else {
            fn_8012976C(action, arg, 0x21, &target_pos, speed);
        }
    } else if (fn_8011EB04(action) == 0x63) {
        result = 1;
    }
    return result;
}
