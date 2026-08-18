extern void* fn_80156938(void*);
extern void fn_8017FE14(void*, void (*)(void));
extern void fn_8019DDBC(void);

void fn_80153104(void* object)
{
    void* runtime;

    if (object != 0) {
        runtime = fn_80156938(object);
        if (runtime != 0) {
            fn_8017FE14(runtime, fn_8019DDBC);
        }
    }
}
