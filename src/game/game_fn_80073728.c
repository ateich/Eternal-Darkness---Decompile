typedef unsigned int u32;

#pragma use_lmw_stmw on

extern u32 fn_80128EE4(void *);
extern void *fn_801A7498(void *);
extern void *fn_801A7490(void *);
extern void *fn_80201814();
extern u32 fn_8003BD48(void *, void *);
extern void *fn_801A717C(void);
extern void fn_8012B344();
extern void fn_801A7470(void *, int);
extern void fn_801A74A0(void *, void *);
extern void fn_801A74A8(void *, void *);
extern unsigned long long fn_8020123C();
extern void fn_801A7228(void *);

u32 fn_80073728(void *object, void *argument)
{
    register void *resolved;
    register void *first;
    register void *second;
    register u32 result;

    result = 0;
    resolved = argument;
    if ((fn_80128EE4(object) & 0x20) != 0) {
        first = fn_801A7498(resolved);
        second = fn_801A7490(resolved);
        resolved = fn_80201814(first);
        fn_80201814(second);
        if (resolved != 0 && object != 0) {
            result = fn_8003BD48(object, argument);
            if ((result & 0x40) != 0) {
                second = fn_801A717C();
                fn_8012B344(object);
                fn_801A7470(second, 0xB);
                fn_801A74A0(second, first);
                fn_801A74A8(second, first);
                fn_8020123C(0x35, first, first, second);
                fn_801A7228(second);
            }
        }
    }
    return result;
}
