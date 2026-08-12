typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;

extern u32 lbl_8064D18C;
extern unsigned short lbl_8064C8A0;
extern u32 fn_80200C38(s32 event);
extern s32 fn_80200C20(s32 event);
extern s32 fn_80201B54(void *object);
extern void *fn_801A717C(void);
extern void fn_801A74A0(void *action, s32 value);
extern void fn_801A74A8(void *action, s32 owner);
extern void fn_801A7538(void *action, s32 value);
extern void fn_801A7518(void *action, s32 value);
extern void fn_801A7588(void *action, s32 value);
extern void fn_801A7470(void *action, s32 kind);
extern unsigned long long fn_8020123C(s32 kind, s32 source, s32 target, s32 value);
extern void fn_801A7228(void *action);

void fn_80068994(void *object, s32 event)
{
    u32 event_kind;
    s32 owner;
    s32 value;
    void *action;

    event_kind = fn_80200C38(event);
    owner = fn_80201B54(object);
    value = fn_80200C20(event);
    if ((event_kind & 0x7FFFFFFF) == lbl_8064D18C) {
        action = fn_801A717C();
        fn_801A74A0(action, value);
        fn_801A74A8(action, owner);
        fn_801A7538(action, 5);
        fn_801A7518(action, (s16)lbl_8064C8A0);
        fn_801A7588(action, 0x8000);
        if ((event_kind & 0x80000000) != 0) {
            fn_801A7470(action, 0xC);
        } else {
            fn_8020123C(0x37, owner, owner, 0);
            fn_801A7470(action, 0xB);
        }
        fn_8020123C(0x27, value, owner, (s32)action);
        fn_801A7228(action);
    }
}
