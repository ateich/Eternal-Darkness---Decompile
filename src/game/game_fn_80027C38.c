typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct EventPayload {
    u32 handle;
    u32 unused;
    u32 value;
} EventPayload;

typedef struct ManagerItem {
    char pad[0x34];
    s32 state;
} ManagerItem;

typedef struct Manager {
    char pad[0xC4];
    ManagerItem* item;
} Manager;

extern u32 lbl_8064C6F8;
extern s32 lbl_8064C700;
extern s32 lbl_8064C708;

extern void* fn_80201B9C(s32);
extern void* fn_80204844(void*, s32);
extern Manager* fn_8006D444(void*);
extern void fn_801E5FB0(u32);
extern void fn_8020123C(s32, s32, u32, s32);
extern s32 fn_8006D2C8(Manager*, s32);
extern u32 fn_80201B54(void*);
extern void fn_80144680(u32);
extern void fn_80045C68(s32);
extern void fn_80144C40(void);

void fn_80027C38(s32 value, EventPayload* payload)
{
    void* object;
    Manager* manager;

    object = fn_80204844(fn_80201B9C(value), 0x20);
    manager = fn_8006D444(object);
    if (payload->handle != 0) {
        fn_801E5FB0(payload->handle);
    }
    fn_8020123C(0x2E, -1, payload->value, 0);
    if (fn_8006D2C8(manager, 0x11) != 0) {
        u32 id = fn_80201B54(object);
        manager->item->state = 2;
        fn_8020123C(0x5C, 0, id, manager->item->state);
        fn_8020123C(0x51, 0, id, 0);
        fn_80144680(lbl_8064C6F8);
        lbl_8064C6F8 = 0;
        fn_80045C68(0);
    }
    fn_80144C40();
    lbl_8064C708 = (s16)value;
    lbl_8064C700 = 0xFF;
}
