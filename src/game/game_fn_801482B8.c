extern void fn_80156904(void*, int);
extern void fn_80156F80(void*, void*);

void fn_801482B8(void* object, void* value, int mode)
{
    fn_80156904(object, mode);
    fn_80156F80(object, value);
}
