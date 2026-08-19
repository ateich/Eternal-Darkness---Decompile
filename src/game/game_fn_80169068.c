typedef struct Value {
    int type;
    int unused;
    union {
        double number;
        void* pointer;
    } data;
} Value;

typedef struct Slot {
    void* fields[5];
    char pad14[44];
} Slot;

typedef struct State {
    Value* top;
    char pad04[0x40];
    Value* current;
    Slot* slots;
} State;

extern Value lbl_8023A868;
extern Value* fn_801672C8(Value*);
extern int fn_80167D2C(Value*);
extern Value* fn_801679F8(State*, Value*, Value*);
extern void fn_8016057C(State*, int);
extern void fn_80160B18(State*, Value*, int);

void fn_80169068(State* state, void* payload)
{
    Value* value = fn_801672C8(state->current);
    void* target = state->slots[fn_80167D2C(value)].fields[4];

    if (target == 0) {
        if (value != &lbl_8023A868) {
            *value = state->top[-1];
        } else {
            Value argument;
            Value* result;

            argument.type = 3;
            argument.data.pointer = payload;
            value = state->top;
            result = fn_801679F8(state, state->current, &argument);
            *result = value[-1];
        }
        return;
    }

    fn_8016057C(state, 3);
    state->top[2] = state->top[-1];
    state->top[1] = *value;
    state->top[0].type = 3;
    state->top[0].data.pointer = payload;
    state->top[-1].data.pointer = target;
    state->top[-1].type = 5;
    state->top += 3;
    fn_80160B18(state, state->top - 4, 0);
}
