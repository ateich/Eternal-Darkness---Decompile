typedef unsigned int u32;

extern u32 fn_80036D5C(void*);
extern void* fn_80201B3C(void);
extern int fn_80204180(void*, void*);
extern void *fn_80201BC8();
extern void fn_801A977C(void*, int);
extern void fn_80036DA4(void*, u32);

int fn_800931D0(register void* object, void* unused1, void* unused2)
{
    register u32 flags = fn_80036D5C(object);
    int result = 0;

    if ((flags & 0x80) && fn_80204180(object, fn_80201B3C()) < 500) {
        if (!(flags & 8)) {
            void* runtime = fn_80201BC8(object);
            flags |= 8;
            fn_801A977C(runtime, 0x17);
        }
        fn_80036DA4(object, flags | 0x800);
        result = 1;
    }
    return result;
}
