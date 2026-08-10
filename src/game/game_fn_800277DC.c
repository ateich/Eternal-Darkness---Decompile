typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct EventPayload {
    u32 first;
    u32 second;
    u32 value;
} EventPayload;

extern s32 lbl_8064C700;
extern s32 lbl_8064C708;

extern void fn_801E5FB0(u32);
extern unsigned long long fn_8020123C();

void fn_800277DC(s16 state, EventPayload* payload)
{
    if (payload->first != 0) {
        fn_801E5FB0(payload->first);
    }
    if (payload->second != 0) {
        fn_801E5FB0(payload->second);
    }
    lbl_8064C700 = 0xFF;
    lbl_8064C708 = state;
    fn_8020123C(0x2E, -1, payload->value, 0);
}
