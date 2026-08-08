typedef int s32;
typedef unsigned int u32;

typedef struct EventState {
    char pad0[8];
    s32 value8;
    char padC[4];
    s32 value10;
    u32 flags;
    s32 value18;
} EventState;

extern u32 lbl_8064C6F8;
extern s32 lbl_8064C700;

extern void fn_80144C40(void);
extern void fn_80144680(u32);
extern void fn_80045C68(s32);
extern void fn_8020123C(s32, s32, s32, s32);
extern void fn_8016B400(s32, s32, s32);
extern void fn_80028198(void);
extern void fn_80027C38(s32, EventState*);

void fn_80027D40(EventState* state, s32 event)
{
    if (event == 1) {
        if (lbl_8064C700 >= 0) {
            lbl_8064C700 -= 5;
            if (lbl_8064C700 <= 0) {
                s32 value18 = state->value18;
                s32 value8 = state->value8;

                fn_80144C40();
                fn_80144680(lbl_8064C6F8);
                lbl_8064C6F8 = 0;
                fn_80045C68(0);
                fn_8020123C(0x2F, -1, state->value8, state->value10);
                fn_8020123C(0x39, -1, state->value8, state->value10);
                if (value18 > 0) {
                    fn_8016B400(value18, 0, value8);
                } else {
                    switch (value18) {
                    case -2:
                        fn_80028198();
                        break;
                    }
                }
            }
            fn_80144C40();
        } else if (state->flags & 1) {
            fn_80027C38(1, state);
            fn_80144C40();
        }
    }
}
