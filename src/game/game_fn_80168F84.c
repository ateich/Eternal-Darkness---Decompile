typedef struct Value {
    int type;
    int unused;
    union {
        double number;
        void* pointer;
    } data;
} Value;

typedef struct Slot {
    void* first;
    void* second;
    void* third;
    void* fourth;
    char pad10[48];
} Slot;

typedef struct State {
    Value* top;
    char pad04[0x40];
    Value* current;
    Slot* slots;
} State;

extern Value* fn_801672C8(Value*);
extern int fn_80167D2C(Value*);
extern void fn_8016057C(State*, int);
extern void fn_80160B18(State*, Value*, int);

Value* fn_80168F84(State* state, void* payload)
{
    Value* value = fn_801672C8(state->current);
    void* target = state->slots[fn_80167D2C(value)].fourth;

    if (target == 0)
        return value;

    fn_8016057C(state, 3);
    state->top[0].data.pointer = target;
    state->top[0].type = 5;
    state->top[1].data.pointer = payload;
    state->top[1].type = 3;
    state->top[2] = *value;
    state->top += 3;
    fn_80160B18(state, state->top - 3, 1);
    return state->top - 1;
}
