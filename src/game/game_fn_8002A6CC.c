typedef int s32;

extern void *fn_80156938();
extern int fn_80201EB8();
extern void *fn_80201BC8();
extern s32 fn_8002A858(void*, void*, void*);
extern void fn_8012EB2C(void*);
extern void fn_8012A254(void*);

s32 fn_8002A6CC(void* callback)
{
    void* source = fn_80156938(callback);
    void* state = (void*)fn_80201EB8(source);
    void* object = fn_80201BC8(source);

    if (object != 0 && fn_8002A858(callback, object, state) != 0) {
        fn_8012EB2C(object);
        fn_8012A254(object);
    }
    return 0;
}
