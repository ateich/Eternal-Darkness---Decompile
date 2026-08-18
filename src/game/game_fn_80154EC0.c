extern void* fn_80156938(void*);
extern void fn_801A2A54(void*, int);

void fn_80154EC0(void* effect, int value)
{
    void* object;
    if (effect != 0) {
        object = fn_80156938(effect);
        if (object != 0) {
            object = *(void**)((char*)object + 0x88);
            if (object != 0)
                fn_801A2A54(object, value);
        }
    }
}
