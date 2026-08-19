extern void *fn_80156938();
extern int fn_801800F8(void*);
extern void fn_80188268(void*);

void fn_80148254(void* object)
{
    void* instance = fn_80156938(object);
    if (fn_801800F8(instance))
        fn_80188268(instance);
}
