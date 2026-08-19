#define FN_80128E30_RETURN void*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern void fn_801296E8(void *, int);

void fn_800C9B74(void *context, void *object)
{
    void *component = fn_80128E30(object);

    if (component != 0) {
        fn_801296E8(component, 6);
    }
}
