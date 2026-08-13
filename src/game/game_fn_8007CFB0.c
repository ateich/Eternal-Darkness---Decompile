typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct CallbackOwner {
    void *object;
} CallbackOwner;

typedef struct CallbackObject {
    u8 pad[0x70];
    void *callback_data;
} CallbackObject;

extern void *fn_801A7498(void *);
extern void *fn_80201814();
extern void *fn_801A7778(void *);
extern void *fn_802053B0(void *, void *);
extern void *fn_80201B8C();
extern void *fn_80201C24(void *);
extern u16 fn_80157994(void *);
extern u16 fn_80157948(void *);
extern void fn_80204EC8(void *, void *);
extern int fn_801E8328(s32, void *);
extern void fn_80157A28(void *, s32);
extern unsigned long long fn_8020123C();
extern void fn_80157C98(void *, s32, s32);

s32 fn_8007CFB0(void *unused, void *object)
{
    void *value;
    void *current;
    void *linked;
    void *related;
    CallbackOwner *owner;
    void *state;

    (void)unused;
    value = fn_801A7498(object);
    current = fn_80201814();
    linked = fn_801A7778(object);
    related = fn_802053B0(current, linked);
    if (current != 0)
        owner = fn_80201B8C(current);
    else
        owner = 0;
    if (linked != 0 && related != 0) {
        state = fn_80201C24(related);
        if ((u16)fn_80157994(state) == 1) {
            fn_80204EC8(current, related);
            fn_801E8328(2, related);
        } else {
            fn_80157A28(state, (u8)(fn_80157994(state) - 1));
        }
        fn_80157A28(linked, (u8)(fn_80157994(linked) + 1));
        if (owner != 0 && owner->object != 0) {
            fn_8020123C(0x10, value,
                        ((CallbackObject *)owner->object)->callback_data, linked);
        }
        fn_80157C98(linked, 0x20, 0);
        fn_80157948(linked);
        fn_80157994(linked);
    }
    return 1;
}
