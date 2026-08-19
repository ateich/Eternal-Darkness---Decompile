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
    void* second;
    char pad08[56];
} Slot;

typedef struct State {
    Value* top;
    char pad04[0x44];
    Slot* slots;
} State;

extern Value* fn_801679F8(State*, Object*, Value*);
extern int fn_80167D2C(Value*);
extern void fn_8016057C(State*, int);
extern void fn_80160B18(State*, Value*, int);
extern void fn_801603AC(State*, Value*, char*);
extern char lbl_8064BBE8;

void fn_80168E34(State* state, Value* key, Value* value)
{
    void* target;

    if (key->type == 4) {
        Object* object = key->data.pointer;
        int index = object->index;
        if (index == 4 || state->slots[index].second == 0) {
            Value* old_top = state->top;
            Value* result = fn_801679F8(state, object, value);
            *result = old_top[-1];
            return;
        }
    }

    target = state->slots[fn_80167D2C(key)].second;
    if (target != 0) {
        fn_8016057C(state, 3);
        state->top[2] = state->top[-1];
        state->top[1] = *value;
        state->top[0] = *key;
        state->top[-1].data.pointer = target;
        state->top[-1].type = 5;
        state->top += 3;
        fn_80160B18(state, state->top - 4, 0);
    } else {
        fn_801603AC(state, key, &lbl_8064BBE8);
    }
}
