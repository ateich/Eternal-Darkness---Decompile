#pragma use_lmw_stmw on

typedef unsigned int u32;
typedef unsigned short u16;

extern void fn_80204A8C(void);
extern void *fn_80201AE4(void);
extern void *fn_80201B8C();
extern void *fn_80201814(void *);
extern void *fn_80201B94(void *);
extern void fn_80201B5C(void *);
extern u32 fn_80201CDC(void *);
extern unsigned long long fn_8020123C(int, void *, void *, int);
extern void fn_80201C24(void *);
extern void fn_80201E50(void *, u32);
extern void fn_8001D9FC(int);
extern void fn_801EFE84(int);
extern void fn_802020B4(void *, int);
extern void fn_80201ADC(void);
extern void fn_80201B3C(void);

void *fn_800E0708(void *object, u16 value, u32 flags)
{
    void *info;
    void *active;
    void *owner;
    void *context;
    void *handle;
    u32 state;

    fn_80204A8C();
    fn_80201AE4();
    info = fn_80201B8C(object);
    owner = *(void **)(*(unsigned char **)((unsigned char *)info + 0x8C) + 0x6C);
    active = fn_80201814(owner);
    if (active != 0) {
        context = fn_80201B8C();
        handle = fn_80201B94(active);
        fn_80201B5C(object);
        state = fn_80201CDC(active);
        *(u16 *)(*(unsigned char **)((unsigned char *)context + 0x80) + 0x2C) = value;
        *(u32 *)(*(unsigned char **)((unsigned char *)context + 0x80) + 0x24) = flags;
        fn_8020123C(8, owner, owner, 0);
        fn_80201C24(active);
        fn_80201E50(handle, state | 0x01000000);
        fn_8001D9FC(2);
        fn_801EFE84(0);
        if ((flags & 2) != 0) {
            fn_802020B4(object, 1);
        } else {
            fn_802020B4(object, 0);
            fn_80201ADC();
            fn_80201B3C();
        }
        *(void **)(*(unsigned char **)((unsigned char *)info + 0x8C) + 0x6C) = 0;
    }
    return owner;
}
