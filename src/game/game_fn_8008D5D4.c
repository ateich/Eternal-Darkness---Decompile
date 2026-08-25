extern void* fn_801A7498(void*);
extern int fn_801A7490(void*);
extern void *fn_80201814();
extern int fn_8003BD48(void*, void*);
extern int fn_80128EE4(void*);
extern void *fn_80201B8C();
extern void* fn_801A717C(void*);
extern void fn_8012B344(void*);
extern void fn_801A7470(void*, int);
extern void fn_801A74A0(void*, void*);
extern void fn_801A74A8(void*, int);
extern unsigned long long fn_8020123C();
extern void fn_801A7228(void*);

typedef struct Runtime8008D5D4 {
    unsigned char pad0[0x50];
    void* value50;
} Runtime8008D5D4;

typedef struct Values8008D5D4 {
    unsigned char pad0[0x1c];
    short timer;
    short value;
} Values8008D5D4;

/* NonMatching: behavior-complete, size-exact C; register allocation differs. */
int fn_8008D5D4(void* object, void* effect)
{
    void* target;
    int value;
    void* mode;
    int flags;
    int state;
    Runtime8008D5D4* runtime;
    void* message;

    target = fn_801A7498(effect);
    value = fn_801A7490(effect);
    mode = fn_80201814(target);
    flags = fn_8003BD48(object, effect);
    state = fn_80128EE4(object);
    if ((flags & 0x40) != 0 && (state & 0x20) != 0) {
        runtime = fn_80201B8C(mode);
        message = fn_801A717C(runtime);
        fn_8012B344(object);
        fn_801A7470(message, 11);
        fn_801A74A0(message, target);
        fn_801A74A8(message, (int)target);
        fn_8020123C(53, target, target, message);
        ((Values8008D5D4*)runtime->value50)->value = 105;
        ((Values8008D5D4*)runtime->value50)->timer = 300;
        fn_801A7228(message);
    }
    return 1;
}
