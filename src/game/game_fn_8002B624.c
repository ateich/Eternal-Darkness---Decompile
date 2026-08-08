extern void* fn_80156938(void*);
extern void fn_800CF03C(void*);

void fn_8002B624(void* callback)
{
    void* object = fn_80156938(callback);
    if (object != 0) {
        fn_800CF03C(object);
    }
}
