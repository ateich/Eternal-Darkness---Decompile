typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned char u8;
typedef float f32;

typedef struct Runtime Runtime;
typedef struct Object80201D2C Object80201D2C;
typedef struct Object80201D14 Object80201D14;

extern void *fn_80201B8C(u8 *object);
extern void *fn_80201BC8(void *object);
extern s32 fn_80201B54(s32 *object);
extern u8 *fn_801294DC(void *owner, s32 kind, s32 flags, s32 mode);
extern void fn_8003CBA8(void);
extern void fn_80128C28(Runtime *runtime, u32 callback, u32 argument);
extern s32 fn_800389E0(void *object, s32 channel, s16 value, s32 propagate);
extern void fn_80201138(s32 kind, void *context, s32 value, s32 id,
                       s32 argument, f32 delay);
extern void fn_80201D2C(Object80201D2C *object, s32 value);
extern void fn_80201D14(Object80201D14 *object, u8 value);
extern const f32 lbl_8064E290;

void fn_8003C86C(void *object)
{
    void *runtime;
    s32 owner;
    u8 *animation;

    fn_80201B8C(object);
    runtime = fn_80201BC8(object);
    owner = fn_80201B54(object);
    animation = fn_801294DC(runtime, 0x2B, 0x24, 10);
    if (animation != 0) {
        fn_80128C28((Runtime *)animation, (u32)fn_8003CBA8, owner);
        fn_800389E0(object, 0, 0, 1);
        fn_80201138(0x11, object, 8, -1, 0, lbl_8064E290);
        fn_80201D2C(object, 8);
        fn_80201D14(object, 1);
    }
}
