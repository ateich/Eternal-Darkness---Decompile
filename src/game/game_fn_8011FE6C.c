#define FN_80128E30_RETURN void*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern void fn_80129CE8(void* object, void* value, int kind, int arg3, int arg4);
extern void fn_80129DE0(void* object, void* value, int arg2, int arg3);

void fn_8011FE6C(void* object)
{
    void* value = fn_80128E30(object);
    fn_80129CE8(object, value, 15, 0, 1);
    fn_80129DE0(object, value, 0, 0);
}
