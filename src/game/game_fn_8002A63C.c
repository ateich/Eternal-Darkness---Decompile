typedef int s32;

extern void* fn_80156938(void*);
extern int fn_80201EB8();
extern void* fn_80201BC8();
extern s32 fn_8002A858(void*, void*, void*);
extern void fn_8012D0D0(void*);
extern void fn_8012EBDC(void*);
extern void fn_80124DBC(void*);

s32 fn_8002A63C(void* callback)
{
    void* source = fn_80156938(callback);
    void* state = (void*)fn_80201EB8();
    void* object = fn_80201BC8(source);

    if (object != 0 && fn_8002A858(callback, object, state) != 0) {
        fn_8012D0D0(object);
        fn_8012EBDC(object);
        fn_80124DBC(object);
    }
    return 2;
}
