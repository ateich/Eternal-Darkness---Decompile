extern void* fn_80156938(void*);
extern void fn_801A29E0(void*);
extern void fn_8017FD6C(void*);

void fn_801544C4(void* object, int enabled)
{
    void* data;

    if (object != 0) {
        data = fn_80156938(object);
        if (data != 0) {
            if (enabled)
                fn_801A29E0(data);
            else
                fn_8017FD6C(data);
        }
    }
}
