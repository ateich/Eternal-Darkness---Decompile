typedef int s32;
typedef unsigned char u8;

extern void* fn_80156938();
extern int fn_80201EB8(void *);
extern void *fn_80201BC8();
extern s32 fn_8002A858(void*, void*, void*);
extern void* fn_8015C910(void);
extern u8 fn_80202160(void*);
extern void fn_8012D0D0(void*);
extern void fn_80124DBC(void*);

s32 fn_8002A590(void* callback)
{
    void* source = fn_80156938(callback);
    void* state = (void*)fn_80201EB8(source);
    void* object = fn_80201BC8(source);

    if (object != 0 && fn_8002A858(callback, object, state) != 0) {
        if (fn_8015C910() == 0 || fn_80202160(source) == 0) {
            fn_8012D0D0(object);
            fn_80124DBC(object);
        }
    }
    return 2;
}
