typedef struct EventState {
    int kind;
    int field4;
    int timer;
    unsigned char padC[0x30];
    void* result;
} EventState;

extern void* fn_800A78E0(void*, EventState*, void*);
extern void* fn_801294DC(void*, int, int, int);
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);

void fn_800A821C(int kind, void* extra, void* context, void* source,
                 EventState* state)
{
    state->kind = kind;
    state->result = fn_800A78E0(context, state, extra);
    if (state->result != 0) {
        fn_801294DC(source, 0x4E, 0x20, 6);
        state->timer = state->timer >= 200 ? state->timer : 200;
        fn_80201D2C(context, 0x40);
        fn_80201D14(context, 1);
    }
}
