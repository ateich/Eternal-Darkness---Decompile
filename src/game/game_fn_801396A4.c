typedef struct Slot {
    int id;
    unsigned char pad04[0x4C];
    signed char flag;
    unsigned char pad4E[2];
} Slot;

typedef struct State {
    int current;
    int unused;
    int request;
    int wanted;
    unsigned char pad10[0x2A8];
    Slot slots[2];
} State;

extern State lbl_805AE020;
extern int fn_8013977C(Slot*);

void fn_801396A4(int id)
{
    State* state = &lbl_805AE020;
    int other = state->current ^ 1;

    if (state->slots[other].id == id) {
        if (state->slots[state->current].id != state->wanted) {
            if (state->slots[state->current].flag != 0) {
                fn_8013977C(&state->slots[state->current]);
            }
            state->slots[state->current].flag = 0;
            state->current = other;
        }
    } else if (state->slots[state->current].id == id &&
               state->slots[other].id != state->wanted) {
        if (state->slots[other].flag != 0) {
            fn_8013977C(&state->slots[other]);
        }
        state->slots[other].flag = 0;
    }
}
