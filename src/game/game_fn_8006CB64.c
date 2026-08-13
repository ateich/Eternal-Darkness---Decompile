typedef signed int s32;
typedef unsigned int u32;

typedef struct State {
    unsigned char pad[0x10];
    u32 fixed_value;
} State;

typedef struct Owner {
    State *state;
} Owner;

extern s32 lbl_8064C8CC;
extern s32 lbl_8064CBC0;
extern void fn_8006CBCC(Owner *owner);

void fn_8006CB64(Owner *owner)
{
    State *state = owner->state;
    s32 limit = 0x546;

    state->fixed_value += lbl_8064C8CC;
    if (lbl_8064CBC0 != 0) {
        limit = 100;
    }
    if ((s32)(state->fixed_value >> 16) >= limit) {
        fn_8006CBCC(owner);
        state->fixed_value = 0;
    }
}
