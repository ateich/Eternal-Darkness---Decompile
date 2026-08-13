typedef unsigned int u32;
typedef unsigned long long u64;

extern void* fn_80201B9C(void*);
extern void* fn_80204844(void*, int);
extern void* fn_8006D444(void);
extern void* fn_80201B54(void*);
extern int fn_801E79FC(void*, int);
extern int fn_8006BCB4(void*);
extern u64 fn_8020123C(int, int, void*, int);
extern void* lbl_8064C4E0;

int fn_800A0C0C(void* state)
{
    int result = 0;
    void* object;
    void* context;
    void* actor;

    object = fn_80204844(fn_80201B9C(state), 0x20);
    context = fn_8006D444();
    actor = fn_80201B54(object);
    if (fn_801E79FC(lbl_8064C4E0, 0x3AA) != 0 && fn_8006BCB4(context) == 0x24) {
        if ((u32)(fn_8020123C(0x54, 0, actor, 0) & 0xFFFFFFFFULL) == 1) {
            result = 1;
        }
    }
    return result;
}
