typedef unsigned int u32;

extern void *fn_80201B9C();
extern void* fn_80204844(void*, int);
extern void* fn_8006D444(void);
extern int fn_80201B54();
extern int fn_801E79FC(void*, int);
extern int fn_8006BCB4(void*);
extern unsigned long long fn_8020123C();
extern void* lbl_8064C4E0;

int fn_800A0B68(void* state)
{
    int result = 0;
    void* object;
    void* context;
    void* actor;

    object = fn_80204844(fn_80201B9C(state), 0x20);
    context = fn_8006D444();
    actor = ((void*)fn_80201B54(object));
    if (fn_801E79FC(lbl_8064C4E0, 0x3AA) != 0 && fn_8006BCB4(context) == 0x24) {
        fn_8020123C(0x52, 0, actor, 0);
        result = 1;
    }
    return result;
}
