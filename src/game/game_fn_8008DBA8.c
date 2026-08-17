#pragma use_lmw_stmw on
extern void* fn_801A7498(void*);
extern int fn_801A7490(void*);
extern void *fn_80201814();
extern int fn_8003BD48(void*, void*);
extern int fn_80128EAC(void*);
extern int fn_801A74B8(void*);
extern int fn_80128EE4(void*);
extern void* fn_801A717C(void*);
extern void fn_8012B344(void*);
extern void fn_801A7470(void*, int);
extern void fn_801A74A0(void*, void*);
extern void fn_801A74A8(void*, int);
extern unsigned long long fn_8020123C();
extern void fn_801A7228(void*);
extern void* fn_80201B94();
extern void fn_80128B10(void*, int);
extern int fn_801290D0(void*);
extern void fn_80128F74(void*, int);
extern void fn_80201DD8(void*, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_8008DBA8(void* object, void* effect)
{
    void* target;
    int value;
    void* mode;
    void* value_mode;
    int flags;
    int state;
    int argument;

    target = fn_801A7498(effect);
    value = fn_801A7490(effect);
    mode = fn_80201814(target);
    value_mode = fn_80201814((void*)value);
    flags = fn_8003BD48(object, effect);
    state = fn_80128EAC(object);
    argument = fn_801A74B8(effect);
    value = fn_80128EE4(object);
    if ((flags & 0x40) != 0 && (value & 0x20) != 0) {
        void* message = fn_801A717C((void*)value);
        fn_8012B344(object);
        fn_801A7470(message, 11);
        fn_801A74A0(message, target);
        fn_801A74A8(message, (int)target);
        fn_8020123C(53, target, target, message);
        *(short*)30 = 105;
        fn_801A7228(message);
    } else if ((flags & 3) != 0 && (state == 4 || state == 5)) {
        void* runtime = fn_80201B94(value_mode);
        fn_80128B10(object, 5);
        fn_80128F74(object, fn_801290D0(object) | 0x200);
        fn_80201DD8(runtime, argument);
        fn_80201D2C(value_mode, 58);
        fn_80201D14(value_mode, 1);
    }
    return 1;
}
