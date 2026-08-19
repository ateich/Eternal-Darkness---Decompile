typedef struct Value {
    int type;
    int unused;
    union {
        double number;
        void* pointer;
    } data;
} Value;

typedef struct Object {
    int unused;
    int index;
} Object;

typedef struct Slot {
    void* first;
    char pad04[4];
    void* second;
    char pad0C[52];
} Slot;

typedef struct State {
    Value* top;
    char pad04[0x44];
    Slot* slots;
} State;

extern Value* fn_8016731C(State*, Object*, Value*);
extern int fn_80167D2C(Value*);
extern void fn_8016057C(State*, int);
extern void fn_80160B18(State*, Value*, int);
extern void fn_801603AC(State*, Value*, char*);
extern char lbl_8064BBE8;

Value* fn_80168CEC(State* state, Value* value)
{
    void* target;
    int index;

    if (value->type == 4) {
        Object* object = value->data.pointer;
        index = object->index;
        if (index == 4 || state->slots[index].first == 0) {
            Value* found = fn_8016731C(state, object, state->top - 1);
            if (found->type == 1) {
                target = state->slots[index].second;
                if (target != 0)
                    goto resolved;
            }
            return found;
        } else {
            goto resolve;
        }
    } else {
resolve:
        index = fn_80167D2C(value);
        target = state->slots[index].first;
    }

resolved:
    if (target != 0) {
        fn_8016057C(state, 2);
        state->top[1] = state->top[-1];
        state->top[0] = *value;
        state->top[-1].data.pointer = target;
        state->top[-1].type = 5;
        state->top += 2;
        fn_80160B18(state, state->top - 3, 1);
        return state->top - 1;
    }

    fn_801603AC(state, value, &lbl_8064BBE8);
    return 0;
}
