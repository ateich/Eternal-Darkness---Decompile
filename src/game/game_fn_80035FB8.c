typedef int s32;

extern void* fn_80201BC8();
extern int fn_80201B64(void*);
extern s32 fn_80201B6C(void*);
extern int fn_80201B5C(void*);
#define fn_80201B5C(a) fn_80201B5C((void*)(a))

extern s32 fn_80201B7C(void*);
extern s32 fn_80201B74(void*);
extern s32 fn_80201B84(void*);
extern int fn_80201B54();

s32 fn_80035FB8(register void* object)
{
    register s32 first;
    register s32 first_other;
    register s32 second;
    register s32 second_other;
    register s32 first_enabled;
    register s32 second_enabled;

    fn_80201BC8(object);
    first = fn_80201B64(object);
    first_other = fn_80201B6C(object);
    second = fn_80201B5C(object);
    second_other = fn_80201B7C(object);
    first_enabled = fn_80201B74(object);
    second_enabled = fn_80201B84(object);

    fn_80201B54(object);

    if ((first_enabled != 0 && first != first_other) ||
        (second_enabled != 0 && second != second_other)) {
        return 1;
    }
    return 0;
}
