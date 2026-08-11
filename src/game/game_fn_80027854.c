typedef int s32;
typedef unsigned int u32;

typedef struct EventPayload {
    u32 first;
    u32 second;
    u32 value;
    u32 other;
    u32 next_value;
    u32 flags;
    s32 next;
} EventPayload;

extern u32 lbl_8064C6F8;
extern s32 lbl_8064C700;

extern void fn_80144C40(void);
extern void fn_80144680(u32);
extern void fn_80045C68(s32);
extern unsigned long long fn_8020123C();
extern void fn_8016B400(int, int, int);
extern void fn_80028198(void);
extern void fn_800277DC(s32, EventPayload*);

void fn_80027854(EventPayload* payload, s32 event)
{
    s32 next;
    u32 value;

    if (event != 1) {
        return;
    }

    if (lbl_8064C700 >= 0) {
        lbl_8064C700 -= 5;
        if (lbl_8064C700 <= 0) {
            next = payload->next;
            value = payload->value;
            fn_80144C40();
            fn_80144680(lbl_8064C6F8);
            lbl_8064C6F8 = 0;
            fn_80045C68(0);
            fn_8020123C(0x2F, -1, payload->value, payload->next_value);
            if (next > 0) {
                fn_8016B400(next, 0, value);
            } else {
                switch (next) {
                case -2:
                    fn_80028198();
                    break;
                }
            }
            fn_8020123C(0xBE, -1, value, 0);
        }
        fn_80144C40();
    } else if (payload->flags & 1) {
        fn_800277DC(1, payload);
        fn_80144C40();
    }
}
