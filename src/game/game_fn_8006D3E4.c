typedef signed int s32;

extern void *fn_80201B9C(void);
extern void *fn_80204844(void *object, s32 kind);
extern void *fn_8006D444(void *object);
extern s32 fn_8006D344(void *owner, s32 first, s32 second);

s32 fn_8006D3E4(s32 first, s32 second)
{
    void *object = fn_80204844(fn_80201B9C(), 0x20);
    void *owner = fn_8006D444(object);

    if (owner != 0) {
        return fn_8006D344(owner, first, second);
    }
    return 0;
}
