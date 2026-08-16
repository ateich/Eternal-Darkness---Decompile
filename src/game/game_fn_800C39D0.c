typedef unsigned char u8;
typedef unsigned short u16;

typedef struct State {
    u8 pad[0x88];
    u16 values[3];
    u8 pad_8e[2];
    u8 flags;
    u8 count;
} State;

extern int lbl_8064C864;
extern int lbl_8064B714;
extern int lbl_8064CA88;

extern State **fn_80201B8C(void *);
extern void *fn_80201B54(void *);
extern void fn_802006D4(void *, void *, int, int, int);

void fn_800C39D0(void *context)
{
    State **state_ref = fn_80201B8C(context);
    void *owner = fn_80201B54(context);
    State *state = *state_ref;

    if (lbl_8064C864 == 0) {
        fn_802006D4(owner, owner, -1, 0x46, 0);
        fn_802006D4(owner, owner, -1, 0x28, 0);
        lbl_8064B714 = -1;
        lbl_8064CA88 = 0;
        state->count = 0;
        state->flags = 0;
        state->values[0] = 0;
        state->values[1] = 0;
        state->values[2] = 0;
    }
}
