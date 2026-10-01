typedef struct Vec3 { float x, y, z; } Vec3;
typedef unsigned char u8;
typedef signed char s8;

typedef struct Flags {
    u8 pad0[0x41];
    s8 value41;
    u8 pad42[3];
    u8 value45;
} Flags;

typedef struct Actor Actor;
typedef struct Item Item;

typedef struct State {
    u8 pad0[0xC];
    Flags* flags;
    u8 pad10[0x80];
    int value90;
} State;

extern void *fn_80201B8C();
extern void* fn_80201B94();
extern void fn_8011F114();
extern u8 fn_80128EE4(void *object);
extern int fn_80201C48(void* value);
extern int fn_80201B54();
extern int fn_80079008(void *context, void *object);
extern void *fn_801294DC(void *, int, int, int);
extern void *fn_801A717C(void);
extern int fn_80072354(int value);
extern void fn_801A7460(void *, int);
extern void fn_801A74A0(void *, int);
extern void fn_801A74A8(void *, int);
extern void fn_801A74C8(void *, int);
extern void fn_801A7560(void *, int);
extern void fn_800CF6AC(void *, int, State *, void *, int, int);
extern void fn_801A7598(void *, int);
extern void fn_801A7550(void *, int);
extern void fn_801A7558(void *, int);
extern void fn_801A764C(void *, Vec3 *);
extern void fn_8003B8A0(void);
extern void fn_80078794(void);
extern void fn_801287C4(void *, void (*)(void), void *, int);
extern void fn_801296F8(void *, int);
extern void fn_80204230(void);
extern void fn_802042A4(void);
extern void fn_80128C28();
extern void fn_80128C44(void *, void (*)(void), void *);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_8007930C(void *arg0, void *arg1)
{
    void* owner;
    int kind;
    int result;
    int value;
    int work;
    void* event;
    int i;
    Item* object;
    Actor* context;
    State* state;
    Vec3 copy;
    Vec3 position;

    context = arg0;
    object = arg1;
    state = fn_80201B8C(context);
    owner = fn_80201B94(context);
    fn_8011F114(&position, object);
    copy = position;
    fn_80128EE4(object);
    result = 0;
    kind = fn_80201C48(owner);
    value = fn_80201B54(context);
    if (fn_80079008(context, object) != 0) {
        result = 0;
    } else if (state->flags->value45 == 0 && state->flags->value41 == 0) {
        owner = fn_801294DC(object, 4, 0, 6);
        if (owner != 0) {
            event = fn_801A717C();
            work = fn_80072354(state->value90);
            fn_801A7460(event, 4);
            fn_801A74A0(event, value);
            fn_801A74A8(event, kind);
            fn_801A74C8(event, 1);
            fn_801A7560(event, 0x704);
            fn_800CF6AC(context, work, state, event, 0, 4);
            fn_801A7598(event, 0x1A4);
            fn_801A7550(event, 0xC);
            fn_801A7558(event, 7);
            fn_801A764C(event, &copy);
            fn_801287C4(owner, fn_8003B8A0, event, 0x22);
            for (i = 0x23; i < 0x2C; i++) {
                fn_801287C4(owner, fn_80078794, event, i);
            }
            fn_801296F8(object, 0x1FD70);
            fn_80128C28(owner, fn_80204230, event);
            fn_80128C44(owner, fn_802042A4, event);
            fn_80201D2C(context, 6);
            fn_80201D14(context, 1);
            result = 1;
        }
    }
    return result;
}
