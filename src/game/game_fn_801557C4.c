extern void *fn_80156938();
extern void fn_801A5860(void*);
extern void fn_8017FD6C(void*);

void fn_801557C4(void* object, int alternate)
{
    void* work;
    if (object != 0 && (work = fn_80156938(object)) != 0) {
        if (alternate != 0)
            fn_801A5860(work);
        else
            fn_8017FD6C(work);
    }
}
