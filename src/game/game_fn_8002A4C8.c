extern void *fn_80156938();
extern void fn_80036E8C(void);
extern void fn_80201750(void*);

void fn_8002A4C8(void* callback)
{
    if (callback != 0) {
        void* object = fn_80156938(callback);
        fn_80036E8C();
        fn_80201750(object);
    }
}
